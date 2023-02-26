/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:48:28 by arcarval          #+#    #+#             */
/*   Updated: 2023/02/25 21:14:17 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include <stdio.h>
#include <signal.h>

void	send_char(int pid, char character)
{
	int	bit;

	// printf("Inside handler function: %d - %c\n", pid, character);
	bit = 0;
	while (bit < 8)
	{
		if ((character & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(150);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	index;

	if (argc != 3)
	{
		printf("Wrong parameters quantity %d! Where is the string?\n", argc);
		return (0);
	}
	pid = ft_atoi(argv[1]);
	printf("PID:%d\n", pid);
	index = 0;
	while (argv[2][index])
	{
		printf("%d : Inside main function.", index);
		send_char(pid, argv[2][index]);
		index++;
	}
	send_char(pid, '\n');
	return (0);
}
