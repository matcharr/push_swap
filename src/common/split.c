/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathis <mathis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023-11-15 10:00:00 by mathis            #+#    #+#             */
/*   Updated: 2023-11-15 10:00:00 by mathis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/* Count the number of words in a string */
static int	count_words(char const *s)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && ft_isspace(s[i]))
			i++;
		if (s[i])
			count++;
		while (s[i] && !ft_isspace(s[i]))
			i++;
	}
	return (count);
}

/* Get the length of a word */
static int	word_len(char const *s, int i)
{
	int	len;

	len = 0;
	while (s[i] && !ft_isspace(s[i]))
	{
		len++;
		i++;
	}
	return (len);
}

/* Free the array of strings */
void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

/* Allocate and fill a word */
static char	*allocate_word(char const *s, int *i)
{
	char	*word;
	int		len;
	int		j;

	len = word_len(s, *i);
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	j = 0;
	while (j < len)
	{
		word[j] = s[*i];
		j++;
		(*i)++;
	}
	word[j] = '\0';
	return (word);
}

/* Split a string into an array of strings */
char	**ft_split(char const *s)
{
	char	**result;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	result = malloc(sizeof(char *) * (count_words(s) + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (j < count_words(s))
	{
		while (s[i] && ft_isspace(s[i]))
			i++;
		result[j] = allocate_word(s, &i);
		if (!result[j])
			return (free_split(result), NULL);
		j++;
	}
	result[j] = NULL;
	return (result);
}
