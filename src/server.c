/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chustei <chustei@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 07:48:32 by chustei           #+#    #+#             */
/*   Updated: 2023/04/13 14:09:30 by chustei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	print_message(int signal)
{
	static int	bit;
	static int	byte;

	if (signal == SIGUSR1)
		byte |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", byte);
		bit = 0;
		byte = 0;
	}
}

int	main(void)
{
	int		pid;

	pid = getpid();
	ft_printf("My PID: %d\n", pid);
	ft_printf("Message me, baby! :*\n", pid);
	ft_printf("--------------------\n");
	while (1)
	{
		signal(SIGUSR1, print_message);
		signal(SIGUSR2, print_message);
		pause ();
	}
	return (0);
}
