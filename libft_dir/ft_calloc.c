/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:42:07 by aait-mal          #+#    #+#             */
/*   Updated: 2022/11/01 11:38:33 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*p;
	size_t	c;

	c = size * count;
	p = malloc(count * size);
	if (!p)
		return (NULL);
	while (c--)
		*(p + c) = 0;
	return (p);
}
