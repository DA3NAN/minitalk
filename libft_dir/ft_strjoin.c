/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 09:29:00 by aait-mal          #+#    #+#             */
/*   Updated: 2022/11/01 12:31:57 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static char	*fill(char *p, const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (*s1)
	{
		p[i] = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		p[i] = *s2;
		s2++;
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	size;
	char	*string;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	string = malloc(size * sizeof(char));
	if (!string)
		return (0);
	string = fill(string, s1, s2);
	return (string);
}
