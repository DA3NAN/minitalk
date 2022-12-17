/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:24:23 by aait-mal          #+#    #+#             */
/*   Updated: 2022/11/03 18:13:13 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strdup(const char *src)
{
	char	*copy;
	size_t	i;
	size_t	len;

	i = 0;
	copy = malloc((ft_strlen((char *)src) + 1) * sizeof(char));
	if (!copy)
		return (0);
	len = ft_strlen((char *)src);
	while (i < len)
	{
		copy[i] = (char)src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
