/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 19:58:07 by mavinici          #+#    #+#             */
/*   Updated: 2021/08/31 11:35:45 by mavinici         ###   ########.fr       */
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

void	get_msg(int sig)
{
	static int	byte;
	static int	bit;
	static char	*str;

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
		}
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
	ft_putendl_fd("\n", 1);
	while (1)
		pause();
	return (0);
}


