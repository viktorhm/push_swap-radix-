/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:24:01 by vharatyk          #+#    #+#             */
/*   Updated: 2024/01/23 18:00:01 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_node **dest, t_node **src)
{
	t_node	*tmp ;

	if (*src == NULL)
		return ;
	tmp = *src ;
	*src = (*src)->next ;
	if (*src)
		(*src)->prev = NULL ;
	tmp ->prev = NULL ;
	if (NULL == *dest)
	{
		*dest = tmp;
		tmp->next = NULL ;
	}
	else
	{
		tmp->next = *dest;
		tmp->next->prev = tmp ;
		*dest = tmp ;
	}
}

void	pa(t_node **a, t_node **b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_node **b, t_node **a)
{
	push(a, b);
	write(1, "pb\n", 3);
}
