/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 14:53:48 by mavinici          #+#    #+#             */
/*   Updated: 2021/08/30 23:04:15 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void		send_message(int pid, int c)
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

void	handle(int pid, char *str)
{
	while (*str)
		send_message(pid, *str++);
	send_message(pid, 0);
}

int			main(int argc, char **argv)
{
	int		pid;
	int		i;

	if (argc != 3)
	{
		ft_putstr_fd("format: ./client pid \"message\"\n", 1);
		exit(0);
	}
	pid = ft_atoi(argv[1]);
	i = 0;
	while (*(*(argv + 2) + i))
		send_message(pid, *(*(argv + 2) + i++));
	send_message(pid, 0);
	return (0);
}
