/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:11:56 by aait-mal          #+#    #+#             */
/*   Updated: 2022/11/03 18:19:06 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static size_t	count_digits(long n)
{
	size_t	count;
	long	nbr;

	nbr = n;
	if (nbr == 0)
		return (1);
	count = 0;
	if (nbr < 0)
	{
		nbr *= -1;
		count++;
	}
	while (nbr > 0)
	{
		nbr = nbr / 10;
		count++;
	}
	return (count);
}

static void	fill_string(char *s, long n, size_t len)
{
	long	nbr;

	nbr = n;
	while (nbr > 0)
	{
		s[len - 1] = (nbr % 10) + '0';
		nbr = nbr / 10;
		len--;
	}
}

char	*ft_itoa(int n)
{
	char	*string;
	size_t	string_len;
	long	nbr;

	nbr = n;
	string_len = count_digits(nbr);
	string = malloc((string_len + 1) * sizeof(char));
	if (!string)
		return (NULL);
	if (nbr < 0)
	{
		nbr *= -1;
		string[0] = '-';
	}
	else if (nbr == 0)
		string[0] = '0';
	string[string_len] = 0;
	fill_string(string, nbr, string_len);
	return (string);
}
