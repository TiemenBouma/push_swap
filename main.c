/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 13:16:07 by tbouma            #+#    #+#             */
/*   Updated: 2022/05/13 17:26:20 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft/libft.h"
#include "includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_lists_a_b	lists;
	t_node		*temp_node;
	int			i;

	i = 1;
	lists.a = ft_new_node(atoi(argv[i]));
	i++;
	while (i < argc)
	{
		temp_node = ft_new_node(atoi(argv[i]));
		ft_node_add_back(&lists.a, temp_node);
		i++;
	}
	status_nodes(&lists.a, &lists.b);
	//swap(&lists.a, SA);
	push(&lists, PB);
	push(&lists, PB);

	// push(&lists, PA);
	//swap_ss(&lists);
	r_rotate(&lists.a, RRA);
	r_rotate(&lists.b, RRB);
	//rotate_rr(&lists);
	status_nodes(&lists.a, &lists.b);
	return (0);
}
