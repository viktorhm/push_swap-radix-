/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:37:17 by vharatyk          #+#    #+#             */
/*   Updated: 2024/01/23 17:49:57 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_node **head)
{
	if ((*head) == NULL || (*head)->next == NULL )
		return (1);
	(*head) = (*head)->next;
	(*head)->prev->next = (*head)->next;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
	return (0);
}

void	sa(t_node **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_node **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_node **a, t_node **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
