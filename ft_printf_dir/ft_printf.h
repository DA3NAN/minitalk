/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 19:10:21 by aait-mal          #+#    #+#             */
/*   Updated: 2022/12/17 18:19:08 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define BASE_HEX_LOW "0123456789abcdef"
# define BASE_HEX_UP "0123456789ABCDEF"

# include<unistd.h>
# include<stdarg.h>
# include "../libft_dir/libft.h"

int		ft_printf(const char *string, ...);
void	check_option(const char *string, va_list arg, int *length);
void	ft_putnbr_fd1(int nb, int fd, int *length);
void	ft_putnbr_unsiged_fd(unsigned int nb, int fd, int *length);
void	ft_putchar_fd1(char c, int fd, int *length);
void	ft_putstr_fd1(char *s, int fd, int *length);
void	ft_putnbr_base(size_t nbr, char *base, int	*length, int C);

#endif
