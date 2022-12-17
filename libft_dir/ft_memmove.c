/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 21:37:58 by aait-mal          #+#    #+#             */
/*   Updated: 2022/10/31 20:59:39 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*csrc;
	unsigned char	*cdst;

	if (!dst && !src)
		return (NULL);
	csrc = (unsigned char *)src;
	cdst = (unsigned char *)dst;
	if (csrc < cdst)
	{
		while (n--)
		cdst[n] = csrc[n];
	}
	else
		ft_memcpy(dst, src, n);
	return (cdst);
}
