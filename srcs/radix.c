/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 12:34:33 by vharatyk          #+#    #+#             */
/*   Updated: 2024/01/27 12:34:34 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	stack_len(t_node **stack)
{
	t_node	*node ;
	int		i;

	i = 0 ;
	node = *stack ;
	while (node)
	{
		i++;
		node = node ->next ;
	}
	return (i);
}

int	get_max_bits(t_node **stack)
{
	t_node	*head;
	int		max;
	int		max_bits;

	head = *stack ;
	max = head->index ;
	max_bits = 0 ;
	while (head)
	{
		if (head->index > max)
			max = head->index ;
		head = head -> next ;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix(t_node **a, t_node **b)
{
	int	i ;
	int	j ;
	int	bits ;
	int	size ;

	i = 0 ;
	size = stack_len(a);
	bits = get_max_bits(a);
	while (i < bits)
	{
		j = 0 ;
		while (j++ < size)
		{
			if ((((*a)->index >> i) & 1) == 1)
				ra(a);
			else
				pb(a, b);
		}
		while (stack_len(b) != 0)
			pa(a, b);
		i++;
	}
}
