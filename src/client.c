/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chustei <chustei@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 11:35:57 by chustei           #+#    #+#             */
/*   Updated: 2023/04/12 14:55:40 by chustei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		if (ft_atoi(av[1]) > 0)
			ft_printf("PID: %d\n", ft_atoi(av[1]), av[2]);
		else
		{
			ft_printf("Error: PID not number or not positive.\n");
			ft_printf("Please provide a valide PID.\n");
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
