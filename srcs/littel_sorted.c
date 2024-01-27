/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   littel_sorted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 12:08:28 by vharatyk          #+#    #+#             */
/*   Updated: 2024/01/27 13:15:12 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_max(t_node *stack)
{
	int	max;

	max = stack->value ;
	while (stack)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next ;
	}
	return (max);
}

static int	get_min(t_node **stack, int number)
{
	t_node	*head;
	int		min;

	head = *stack;
	min = head->index;
	while (head->next)
	{
		head = head->next;
		if ((head->index < min) && head->index != number)
			min = head->index;
	}
	return (min);
}

void	little_sort3(t_node **stack)
{
	int	max_high;

	max_high = find_max(*stack);
	if ((*stack)->value == max_high)
		ra(stack);
	else if ((*stack)->next->value == max_high)
		rra(stack);

	if ((*stack)->value > (*stack)->next->value)
		sa(stack);
}

void	little_sort4(t_node **a, t_node **b)
{
	int	len;

	len = get_distance_node(a, get_min(a, -1));
	if (len == 1)
		ra(a);
	else if (len == 2)
	{
		ra(a);
		ra(a);
	}
	else if (len == 3)
		rra(a);
	if (!ordenar(*a))
		return ;
	pb(a, b);
	little_sort3(a);
	pa(a, b);
}

void	little_sort5(t_node **a, t_node **b)
{
	int	distance;

	distance = get_distance_node(a, get_min(a, -1));
	if (distance == 1)
		ra(a);
	else if (distance == 2)
	{
		ra(a);
		ra(a);
	}
	else if (distance == 3)
	{
		rra(a);
		rra(a);
	}
	else if (distance == 4)
		rra(a);
	if (!ordenar(*a))
		return ;
	pb(a, b);
	little_sort4(a, b);
	pa(a, b);
}
