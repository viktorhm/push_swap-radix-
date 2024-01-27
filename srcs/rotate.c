/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:12:44 by vharatyk          #+#    #+#             */
/*   Updated: 2024/01/19 15:15:44 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_node **stack)
{
	t_node	*last_node ;

	if (*stack == NULL)
		return ;
	last_node = find_last_node(*stack);
	last_node->next = *stack ;
	*stack = (*stack)->next ;
	(*stack)->prev = NULL ;
	last_node->next->prev = last_node ;
	last_node->next->next = NULL ;
}

void	ra(t_node **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_node **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_node **a, t_node **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
