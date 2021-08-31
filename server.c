/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 19:58:07 by mavinici          #+#    #+#             */
/*   Updated: 2021/08/30 20:55:21 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdio_ext.h>
#include "minitalk.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}


void	get_msg(int sig)
{
	static int	byte;
	static int	bit;

	if (sig == SIGUSR2)
		byte += 1 << (7 - bit);
	if (++bit == 8)
	{
		if (byte)
			ft_putchar_fd(byte, 1);
		else
			ft_putchar_fd('\n', 1);
		bit = 0;
		byte = 0;
	}

}

int	main()
{
	struct sigaction sa;
	


	sa.sa_handler = get_msg;
	sa.sa_flags = 0;
	if (sigemptyset(&sa.sa_mask) == -1
		|| sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
		return (-1);
	ft_putnbr_fd(getpid(), 1);
	ft_putendl_fd("", 1);
	while (1)
		pause();
	return (0);
}


