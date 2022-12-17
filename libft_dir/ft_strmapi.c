/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 19:52:30 by aait-mal          #+#    #+#             */
/*   Updated: 2022/10/31 20:20:24 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*new_s;
	size_t	index;
	size_t	len;

	if (!s || !f)
		return (NULL);
	new_s = malloc((ft_strlen(s) + 1) * sizeof(char));
	if (!new_s)
		return (NULL);
	index = 0;
	len = ft_strlen(s);
	while (index < len)
	{
		new_s[index] = f(index, s[index]);
		index++;
	}
	new_s[index] = '\0';
	return (new_s);
}
