/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:12:44 by aait-mal          #+#    #+#             */
/*   Updated: 2022/10/31 16:55:58 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstsize;
	size_t	srcsize;
	size_t	i;

	srcsize = ft_strlen(src);
	if (!dst && size == 0)
		return (srcsize + size);
	dstsize = ft_strlen(dst);
	if (size <= dstsize)
		return (srcsize + size);
	while (*dst)
		dst++;
	i = 0;
	while (src[i] && i < size - dstsize - 1)
	{
		*dst++ = src[i];
		i++;
	}
	*dst = '\0';
	return (dstsize + srcsize);
}
