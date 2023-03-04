/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:05:49 by arcarval          #+#    #+#             */
/*   Updated: 2023/03/04 14:40:12 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "ft_printf/ft_printf.h"

static void	signal_action(int signal)
{
	static int	bit;
	static int	character;

	if (signal == SIGUSR1)
		character |= (0x01 << bit);
	if (signal == SIGUSR2)
		character &= ~(0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_putchar_fd(character, 1);
		bit = 0;
		character = 0;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("\033[0;31mWait a minute!");
		ft_printf("There is more than enough parameters.\033[0m\n");
		return (0);
	}
	pid = getpid();
	ft_printf("\033[0;33mPID Process: %d\033[0m\n", pid);
	signal(SIGUSR1, signal_action);
	signal(SIGUSR2, signal_action);
	while (1)
	{
		pause();
	}
	return (0);
}
