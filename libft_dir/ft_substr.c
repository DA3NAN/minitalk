/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 11:37:55 by aait-mal          #+#    #+#             */
/*   Updated: 2022/11/01 12:41:35 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	index;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (len > s_len - start)
		len = s_len - start;
	if (start > s_len)
		len = 0;
	substring = malloc((len + 1) * sizeof(char));
	if (!substring)
		return (NULL);
	index = 0;
	while (index < len && start <= s_len)
	{
		substring[index] = s[start];
		start++;
		index++;
	}
	substring[index] = '\0';
	return (substring);
}
