/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chustei <chustei@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 11:35:57 by chustei           #+#    #+#             */
/*   Updated: 2023/04/11 14:45:41 by chustei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	int	pid = getpid();
	ft_printf("<PID>: %d\n", pid);
	if (ac == 3)
	{
		ft_printf("We have 2 arguments\n");
		ft_printf("\"%s\" && \"\"%s\"\n", av[1], av[2]);
	}
	else
		ft_printf("We don't have 2 argumets\n");
	return (0);
}
