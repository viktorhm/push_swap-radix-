/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 19:12:32 by vharatyk          #+#    #+#             */
/*   Updated: 2024/01/17 17:02:44 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
Décale d’une position vers le bas tous les élements de
la pile a. Le dernier élément devient le premier
*/

static void	reverse_rotate(t_node **stack)
{
	t_node	*last_node ;

	if (*stack == NULL)
		return ;
	last_node = find_last_node(*stack);
	last_node->prev->next = NULL ;
	last_node->next = *stack;
	last_node->prev = NULL ;
	*stack = last_node;
	last_node->next->prev = last_node ;
}

void	rra(t_node **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_node **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_node **a, t_node **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
}
