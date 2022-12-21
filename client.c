/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 20:57:37 by aait-mal          #+#    #+#             */
/*   Updated: 2022/12/21 14:23:23 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	check_valid_pid(char *p)
{
	int	i;

	i = 0;
	while (p[i])
	{
		if (ft_isdigit(p[i]))
			i++;
		else
			return (0);
	}
	if (ft_atoi(p) < 0)
		return (0);
	return (1);
}

static void	char_bin(char *pid, int c)
{
	int		i;

	i = 8;
	while (i--)
	{
		if (c & (1 << i))
			kill(ft_atoi(pid), SIGUSR1);
		else
			kill(ft_atoi(pid), SIGUSR2);
		usleep(500);
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3 || !check_valid_pid(argv[1]))
		ft_printf("Please include a valid pid and one message!");
	else
	{
		while (*argv[2])
		{
			char_bin(argv[1], *argv[2]);
			argv[2]++;
		}
	}
	return (0);
}
