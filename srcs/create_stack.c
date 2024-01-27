/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 13:45:51 by vharatyk          #+#    #+#             */
/*   Updated: 2024/01/27 13:16:33 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_last_node(t_node *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->next)
		stack = stack ->next ;
	return (stack);
}

int	error_char(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if ((argv[i] >= '0' && argv[i] <= '9'))
			i++;
		else if (argv[0] == '-')
		{
			if (argv[1] > '0' && argv[1] <= '9')
				i++;
			else
				return (1);
		}
		else
			return (1);
	}
	return (0);
}

int	not_repet(int nbr, t_node *a)
{
	if (a == NULL)
		return (0);
	while (a)
	{
		if (a->value == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}

int	error_free(t_node **a ,int leak)
{
	if(leak == 1)
		free_stack(*a);
	write(1, "erreur", 4);
	return (0);
}

int	init_stack(t_node **a, char **argv, int leak)
{
	int long	nbr;
	int			i;

	i = 0 ;
	while (argv[i])
	{
		if (error_char(argv[i]))
			error_free(a,leak);
		nbr = ft_atoi(argv[i]);
		if (nbr > 2147483647 || nbr < -2147483648)
			error_free(a, leak);
		if (not_repet(nbr, *a))
			error_free(a, leak);
		else
			add_node(a, (int)nbr);
		i++;
	}
	return (i);
}
