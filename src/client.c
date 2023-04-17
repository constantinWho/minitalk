/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chustei <chustei@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 11:35:57 by chustei           #+#    #+#             */
/*   Updated: 2023/04/13 16:55:39 by chustei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

void	send_bit(int pid, int bit)
{
	if (bit == 1)
	{
		if (kill(pid, SIGUSR1) != 0)
		{
			ft_printf("Error: failed to send signal to PID %d\n", pid);
			exit(1);
		}
	}
	else if (bit == 0)
	{	
		if (kill(pid, SIGUSR2) != 0)
		{
			ft_printf("Error: failed to send signal to PID %d\n", pid);
			exit(1);
		}
	}
	else
	{
		ft_printf("Error: invalid bit value %d\n", bit);
		exit(1);
	}
}

void	send_byte(int pid, unsigned char byte)
{
	int	i;
	int	bit;

	i = -1;
	while (++i < 8)
	{
		bit = (byte >> i) & 1;
		send_bit(pid, bit);
		usleep(300);
	}
}

void	send_message(int pid, char *message)
{
	int	i;

	i = -1;
	while (message[++i])
		send_byte(pid, message[i]);
	send_byte(pid, '\n');
}

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		if (ft_atoi(av[1]) > 0)
			send_message(ft_atoi(av[1]), av[2]);
		else
		{
			ft_printf("Error: Invalid PID\n");
			return (1);
		}
	}
	else if (ac < 3)
	{
		ft_printf("Error: too few arguments.\n");
		ft_printf("Please provide exactly 2 arguments.\n");
		return (1);
	}
	else
	{
		ft_printf("Error: too many arguments.\n");
		ft_printf("Please provide exactly 2 arguments.\n");
		return (1);
	}
	return (0);
}
