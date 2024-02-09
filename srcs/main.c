/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 12:59:06 by vharatyk          #+#    #+#             */
/*   Updated: 2024/02/09 10:48:40 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ordenar(t_node *stack )
{
	int	min ;
	int	i;

	min = stack->value;
	i = 0;
	while (stack)
	{
		if (min <= stack->value)
		{
			min = stack->value;
			stack = stack -> next;
			i++;
		}
		else
			return (1);
	}
	return (0);
}

void	free_argv(char **argv, int leak)
{
	int	j;

	j = 0 ;
	if (leak == 1)
	{
		while (argv[j])
		{
			free(argv[j]);
			j++;
		}
		free(argv);
	}
}

void	how_to_sort(t_node **a, t_node **b, int nb_value)
{
	if (nb_value != 0)
	{
		get_index(a);
		if (nb_value == 2 && ordenar(*a))
			sa(a);
		else if (nb_value == 3 && ordenar(*a))
			little_sort3(a);
		else if (nb_value == 4 && ordenar(*a))
			little_sort4(a, b);
		else if (nb_value == 5 && ordenar(*a))
			little_sort5(a, b);
		else if (nb_value > 5 && ordenar(*a))
			radix(a, b);
	}
}

int	main(int argc, char *argv[])
{
	t_node	*a;
	t_node	*b;
	int		nb_value;

	a = NULL ;
	b = NULL ;
	if (argc == 1)
	{
		write(1, "\n", 1);
		return (0);
	}
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		nb_value = init_stack(&a, argv, 1);
		free_argv(argv, 1);
	}
	else
		nb_value = init_stack(&a, argv + 1, 0);
	if (nb_value == 1)
		return (0);
	how_to_sort(&a, &b, nb_value);
	free_stack(a);
	free_stack(b);
	return (0);
}
