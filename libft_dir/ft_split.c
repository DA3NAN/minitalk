/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 13:50:55 by aait-mal          #+#    #+#             */
/*   Updated: 2022/11/04 10:54:20 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static size_t	count_words(const char *s, char c)
{
	size_t	count;
	size_t	first;

	count = 0;
	while (*s)
	{
		first = 1;
		while (*s == c)
			s++;
		while (*s != c && *s)
		{
			if (first == 1)
				count++;
			first = 0;
			s++;
		}
	}
	return (count);
}

static size_t	count_word_length(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (s[count] != c && s[count])
		count++;
	return (count);
}

static void	fill_word(char *s1, const char *s2, size_t len)
{
	size_t	index;

	index = 0;
	while (index < len)
	{
		s1[index] = s2[index];
		index++;
	}
	s1[index] = 0;
}

static void	*free_all(char **p, size_t j)
{
	size_t	i;

	i = 0;
	while (i < j)
	{
		free(p[i]);
		i++;
	}
	free(p);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	size_t	words_number;
	size_t	word_length;
	size_t	index;
	char	**result;

	if (!s)
		return (NULL);
	words_number = count_words(s, c) + 1;
	result = malloc(words_number * sizeof(result));
	if (!result)
		return (NULL);
	index = -1;
	while (++index < words_number - 1)
	{
		while (*s == c)
			s++;
		word_length = count_word_length(s, c);
		result[index] = malloc((word_length + 1) * sizeof(char));
		if (!result[index])
			return (free_all(result, index));
		fill_word(result[index], s, word_length);
		s = s + word_length;
	}
	result[index] = NULL;
	return (result);
}
