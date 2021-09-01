/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 19:58:07 by mavinici          #+#    #+#             */
/*   Updated: 2021/09/01 09:28:20 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static char	*store_bytes(char *str, char c)
{
	char	*tmp;
	int		i;

	tmp = malloc((ft_strlen(str) + 2) * sizeof(char));
	if (tmp == NULL)
	{
		if (str)
			free(str);
		return (NULL);
	}
	if (!str)
	{
		*(tmp) = c;
		*(tmp + 1) = '\0';
		return (tmp);
	}
	i = -1;
	while (*(str + ++i))
		*(tmp + i) = *(str + i);
	*(tmp + i) = c;
	*(tmp + i + 1) = '\0';
	free(str);
	return (tmp);
}

static void	get_msg(int sig, siginfo_t *info, void *ucontext)
{
	static int	byte;
	static int	bit;
	static char	*str;

	(void)ucontext;
	if (sig == SIGUSR2)
		byte += 1 << (7 - bit);
	if (++bit == 8)
	{
		if (byte)
			str = store_bytes(str, byte);
		else
		{
			write(1, str, ft_strlen(str));
			write(1, "\n\n", 2);
			free(str);
			str = NULL;
			kill(info->si_pid, SIGUSR1);
		}
		bit = 0;
		byte = 0;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	number;

	number = 0;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		number = n * -1;
	}
	else
		number = n;
	if (number >= 10)
	{
		ft_putnbr_fd(number / 10, fd);
	}
	ft_putchar_fd(number % 10 + '0', fd);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = get_msg;
	if (sigemptyset(&sa.sa_mask) == -1
		|| sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
		return (-1);
	write(1, "\nPID: ", 7);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n\n", 2);
	while (1)
		pause();
	return (0);
}
