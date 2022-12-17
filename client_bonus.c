/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:01:53 by aait-mal          #+#    #+#             */
/*   Updated: 2022/12/17 19:35:23 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler_response(int c)
{
	if (c == 30)
	{
		ft_printf("Server : OK\n");
	}
}

void	char_bin(char *p, int c)
{
	int		i;

	i = 8;
	while (i--)
	{
		if (c & (1 << i))
			kill(ft_atoi(p), SIGUSR1);
		else
			kill(ft_atoi(p), SIGUSR2);
		usleep(500);
		signal(SIGUSR1, handler_response);
	}
}

int	main(int argc, char **argv)
{
	if (argc < 3)
		ft_printf("Please include the server pid and the message!");
	else
	{
		while (*argv[2])
		{
			char_bin(argv[1], *argv[2]);
			argv[2]++;
		}
		char_bin(argv[1], *argv[2]);
	}
	return (0);
}
