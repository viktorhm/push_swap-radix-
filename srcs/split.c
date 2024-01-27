/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vharatyk <vharatyk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 12:43:35 by vharatyk          #+#    #+#             */
/*   Updated: 2024/01/27 13:18:03 by vharatyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(char const *str)
{
	int	i;

	i = 0 ;
	while (str[i])
		i++;
	return (i);
}

static int	nb_mots(const char *str, char c)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (i);
}

static char	*created_word(const char *str, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc ((end - start + 1) * sizeof(char));
	while (start < end)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**lst;

	lst = malloc((nb_mots(s, c) + 1) * sizeof(char *));
	if (!s || !lst)
		return (0);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			lst[j++] = created_word(s, index, i);
			index = -1;
		}
		i++;
	}
	lst[j] = 0;
	return (lst);
}
