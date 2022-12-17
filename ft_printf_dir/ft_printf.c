/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:09:42 by aait-mal          #+#    #+#             */
/*   Updated: 2022/12/16 12:02:11 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_printf(const char *string, ...)
{
	va_list	arg;
	int		length;

	length = 0;
	va_start(arg, string);
	while (*string)
	{
		if (*string == '%')
		{
			string++;
			if (!(*string))
				break ;
			check_option(string, arg, &length);
		}
		else
			ft_putchar_fd1(*string, 1, &length);
		string++;
	}
	va_end(arg);
	return (length);
}
