/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 19:29:49 by mavinici          #+#    #+#             */
/*   Updated: 2021/08/31 19:23:21 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <signal.h>
# include <unistd.h>
# include <string.h>
# include <sys/types.h>
# include <stdlib.h>
#define YELL "\e[0;33m"
#define GRN "\e[0;32m"

size_t	ft_strlen(char *s);
void	ft_putchar_fd(char c, int fd);
int	ft_atoi(const char *nptr);
