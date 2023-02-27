/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:05:49 by arcarval          #+#    #+#             */
/*   Updated: 2023/02/27 19:32:52 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "ft_printf/ft_printf.h"
#include <signal.h>

void	handle_signal(int signal)
{
	static int	bit;
	static int	i;

	// When receiving a SIGUSR1, it means it received a 1
	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	// If it receives a SIGUSR2, it means it received a 0
	if (signal == SIGUSR2)
		i &= ~(0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_putchar_fd(i, 1);
		bit = 0;
		i = 0;
	}
}

// Still bugging when receiving a super big string
int	main(int argc, char **argv)
{
	int	pid;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("Error! There is more than enough parameters.\n");
		return (0);
	}
	pid = getpid();
	ft_printf("PID Process: %d\n", pid);
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
	{
		pause();
	}
	return (0);
}
