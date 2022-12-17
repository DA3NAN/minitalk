/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 11:34:42 by aait-mal          #+#    #+#             */
/*   Updated: 2022/11/03 18:09:51 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	is_included(const char *set, char c)
{
	size_t	index;

	index = 0;
	while (set[index])
	{
		if (set[index] == c)
			return (1);
		index++;
	}
	return (0);
}

static char	*check_set_first(char *s1, const char *set)
{
	while (*s1 && is_included(set, *s1))
		s1++;
	return (s1);
}

static	char	*check_set_end(char *s1, const char *set)
{
	size_t	s1_len;
	char	*result;

	s1_len = ft_strlen(s1);
	while (s1_len > 0 && is_included(set, s1[s1_len - 1]))
		s1_len--;
	result = malloc((s1_len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, s1_len + 1);
	return (result);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*string;
	size_t	index;

	if (!s1 || !set)
		return (NULL);
	string = (char *)s1;
	index = 0;
	string = check_set_first(string, set);
	string = check_set_end(string, set);
	return (string);
}
