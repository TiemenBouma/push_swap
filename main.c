/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 13:16:07 by tbouma            #+#    #+#             */
/*   Updated: 2022/05/27 10:44:50 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft/libft.h"
#include "includes/push_swap.h"

static int	isdigit(int c)
{
	return ((c >= '0' && c <= '9') || c == '-');
}

static int	check_nummbers(char **argv)
{
	int	i;
	int	k;

	i = 1;
	while (argv[i])
	{
		k = 0;
		while (argv[i][k])
		{
			if (!(isdigit(argv[i][k])))
			{
				write(2, "ERROR\n", 6);
				return (0);
			}
			k++;
		}
		i++;
	}
	return (1);
}

static t_lists_a_b	*make_list(int argc, char **argv)
{
	int			i;
	t_node		*temp_node;
	t_lists_a_b	*lists;

	lists = malloc(sizeof(t_lists_a_b));
	if (lists == NULL)
		exit(0);
	lists->a = NULL;
	lists->b = NULL;
	i = 1;
	lists->a = ft_new_node(atoi(argv[i]));
	i++;
	while (i < argc)
	{
		temp_node = ft_new_node(atoi(argv[i]));
		ft_list_node_add_back(&lists->a, temp_node);
		i++;
	}
	return (lists);
}

int	main(int argc, char **argv)
{
	t_lists_a_b	*lists;
	int			length_list;

	if (!(check_nummbers(argv)))
		return (0);
	lists = make_list(argc, argv);
	list_make_index_bucket(&lists->a);
	length_list = ft_list_size(lists->a);
	if (length_list == 2)
		sort2(&lists->a);
	else if (length_list == 3)
		sort3(&lists->a);
	else if (length_list == 4)
		sort4(lists);
	else if (length_list == 5)
		sort5(lists);
	else if (length_list > 5)
		bucketsort(lists);
	exit(0);
	return (0);
}
