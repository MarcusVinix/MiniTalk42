/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavinici <mavinici@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 19:29:49 by mavinici          #+#    #+#             */
/*   Updated: 2021/08/27 12:28:31 by mavinici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "./42libft/libft.h"

typedef struct s_msg
{
	char	c;
	size_t	size;
}			t_msg;
