/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aait-mal <aait-mal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:01:08 by aait-mal          #+#    #+#             */
/*   Updated: 2022/12/21 14:28:10 by aait-mal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	sigusr_handler(int signum, siginfo_t *info, void *context)
{
	static unsigned char	c = 0;
	static int				i = 7;
	static int				pid_sender;

	(void) context;
	if (!pid_sender)
		pid_sender = info->si_pid;
	if (pid_sender != info->si_pid)
	{
		c = 0;
		i = 7;
		pid_sender = info->si_pid;
	}
	if (signum == SIGUSR1)
		c |= (1 << i);
	if (i == 0)
	{
		ft_printf("%c", c);
		if (!c)
			kill(pid_sender, SIGUSR1);
		i = 7;
		c = 0;
	}
	else
		i--;
}

int	main(void)
{
	int					pid;
	struct sigaction	action;

	action.sa_sigaction = sigusr_handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_SIGINFO;
	pid = getpid();
	if (sigaction(SIGUSR1, &action, 0) < 0)
		return (1);
	if (sigaction(SIGUSR2, &action, 0) < 0)
		return (1);
	ft_printf("%d\n", pid);
	while (1)
		pause();
	return (0);
}
