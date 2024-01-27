/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 19:41:41 by vharatyk          #+#    #+#             */
/*   Updated: 2024/01/21 13:04:09 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_node *stack)
{
	t_node	*next_node;

	if (stack == NULL)
		return ;
	while (stack)
	{
		next_node = stack->next;
		free(stack);
		stack = next_node ;
	}
	stack = NULL;
}

void	add_node(t_node **stack, int nbr)
{
	t_node	*node ;
	t_node	*last_node;

	if (NULL == stack)
		return ;
	node = malloc(sizeof(t_node));
	if (node == NULL)
		return ;
	node->index = -1;
	node->next = NULL;
	node->value = nbr;
	if (*stack == NULL)
	{
		*stack = node ;
		node->prev = NULL ;
	}
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = node ;
		node->prev = last_node ;
	}
}

static t_node	*get_next_min(t_node **stack)
{
	t_node	*head;
	t_node	*min;
	int		has_min;

	min = NULL;
	has_min = 0;
	head = *stack;
	if (head)
	{
		while (head)
		{
			if ((head->index == -1) && (!has_min || head->value < min->value))
			{
				min = head;
				has_min = 1;
			}
			head = head->next;
		}
	}
	return (min);
}

void	get_index(t_node **stack)
{
	t_node	*head;
	int		index;

	index = 0;
	head = get_next_min(stack);
	while (head)
	{
		head->index = index++;
		head = get_next_min(stack);
	}
}
