/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 14:53:48 by mavinici          #+#    #+#             */
/*   Updated: 2021/08/31 21:20:54 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	confirm(int sig)
{
	(void)sig;
	write(1, GRN"MESSAGE RECEIVED :)", 26);
	write(1, "\n", 1);
	exit(0);
}

void	ft_putendl_fd(char *s, int fd)
{
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
	write(fd, "\n", 1);
}

int	erro(char *message)
{
	ft_putendl_fd(message, 1);
	return (0);
}

void	send_message(int pid, int c)
{
	int	bit;

	bit = 8;
	while (bit--)
	{
		if (!(c & 1 << bit))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	int		i;

	if (argc != 3)
		return (erro(YELL"\nformat: \n./client pid \"message"YELL"\"\n"));
	pid = ft_atoi(argv[1]);
	i = 0;
	signal(SIGUSR1, confirm);
	while (*(*(argv + 2) + i))
		send_message(pid, *(*(argv + 2) + i++));
	send_message(pid, 0);
	while (1)
		pause();
	return (0);
}
