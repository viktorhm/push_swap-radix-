/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 12:53:17 by vharatyk          #+#    #+#             */
/*   Updated: 2024/01/27 13:18:33 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	int				value;
	int				index;
}		t_node;

/* littel sorted */
void	little_sort3(t_node **stack);
void	little_sort4(t_node **a, t_node **b);
void	little_sort5(t_node **a, t_node **b);

/*radix*/
int		get_max_bits(t_node **stack);
void	radix(t_node **a, t_node **b);

//main
int		ordenar(t_node *stack);
void	free_argv(char **argv, int leak);
void	how_to_sort(t_node **a, t_node **b, int nb_value);
int		main(int argc, char *argv[]);

//init
void	free_stack(t_node *stack);
void	add_node(t_node **stack, int nbr);
void	get_index(t_node **stack);

//created stack
t_node	*find_last_node(t_node *stack);
int		error_char(char *argv);
int		not_repet(int nbr, t_node *a);
int		error_free(t_node **a, int leak);
int		init_stack(t_node **a, char **argv, int leak );

// split
size_t	ft_strlen(char const *str);
char	**ft_split(char const *s, char c);

// ft_atoi
int		get_distance_node(t_node **stack, int index);
long	ft_atoi(const char *str);
// base
void	sa(t_node **head);
void	sb(t_node **head);
void	ss(t_node **a, t_node **b);
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);

#endif
