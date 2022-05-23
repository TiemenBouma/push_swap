/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouma <tbouma@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:49:14 by tbouma            #+#    #+#             */
/*   Updated: 2022/05/23 15:30:12 by tbouma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft/libft.h"
#include "../includes/push_swap.h"

//Calculate the amount in each bucket, and puts the value in a_i_b (amount in this bucket)
void	do_bucket_stuff(t_node **list_a, int amount_of_buckets)
{
	int	arr[amount_of_buckets];
	int	i;
	t_node	*current;

	i = 0;
	while (amount_of_buckets > i)
	{
		arr[i] = 0;
		i++;
	}
	current = *list_a;
	i = 0;
	while (current)
	{
		(arr[current->b_n])++;
		current = current->n;
	}
	i = 0;
	current = *list_a;
	while (current)
	{
		current->a_i_b = arr[current->b_n];
		current = current->n;
	}
}

int	find_amount_of_buckets(int length_list)
{
	if (length_list < 10)
		return (1);
	else if (length_list >= 10 && length_list <= 50)
		return (2);
	else if (length_list > 50 && length_list <= 250)
		return (6);
	else if (length_list > 250 && length_list <= 500)
		return (11);
	return (15);
}

static int	find_low(t_node **list_a)
{
	t_node	*current;
	int		lo;

	current = *list_a;
	lo = INT_MAX;
	while (current)
	{
		if (current->c < lo && current->i < 0)
			lo = current->c;
		current = current->n;
	}
	return (lo);
}

static int	find_high(t_node **list_a)
{
	t_node	*current;
	int		hi;

	current = *list_a;
	hi = INT_MIN;
	while (current)
	{
		if (current->c > hi && current->i < 0)
			hi = current->c;
		current = current->n;
	}
	return (hi);
}

static int	need_indexing(t_node **list_a)
{
	t_node	*current;
	int		need_indexing;

	need_indexing = 0;
	current = *list_a;
	while (current)
	{
		if (current->i < 0)
			need_indexing++;
		current = current->n;
	}
	return (need_indexing);
}

void	do_indexing(t_node **list_a, int buckets, int size, int range)
{
	t_node	*current;
	int		i;
	int		lo;
	int		hi;

	i = 0;
	current = *list_a;
	while (need_indexing(list_a))
	{
		lo = find_low(list_a);
		hi = find_high(list_a);
		while (current)
		{
			if (current->c == lo)
			{
				current->i = i;
				current->b_n = current->i / range;
				current->a_b = buckets;
				current->t_l_s = size;
			}
			if (current->c == hi)
			{
				current->i = size - 1 - i;
				current->b_n = current->i / range;
				current->a_b = buckets;
				current->t_l_s = size;
			}
			current = current->n;
		}
		i++;
		current = *list_a;
	}
}

void	ft_list_make_index_bucket(t_node **list_a)
{

	int		buckets;
	int		size;
	int		range;

	size = ft_list_size(*list_a);
	buckets = find_amount_of_buckets(size);
	range = (size) / buckets;
	do_indexing(list_a, buckets, size, range + 1);
	do_bucket_stuff(list_a, buckets);

}
