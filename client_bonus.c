/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:48:28 by arcarval          #+#    #+#             */
/*   Updated: 2023/03/03 16:13:44 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Libft/libft.h"
#include "ft_printf/ft_printf.h"

static void	send_char(int pid, char character)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((character & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(200);
		bit++;
	}
}

static void	end_of_string_sent(int signal)
{
	ft_printf("\n\033[0;32mAll done 😄. SIG: %d!!!\033[0m\n", signal);
}

int	main(int argc, char **argv)
{
	int	pid;
	int	index;

	if (argc != 3)
	{
		ft_printf("\033[0;31mWrong parameters quantity!\033[0m\n");
		ft_printf("It should be \"./client <PID> <Text>.\"\n");
		return (0);
	}
	signal(SIGUSR1, end_of_string_sent);
	signal(SIGUSR2, end_of_string_sent);
	pid = ft_atoi(argv[1]);
	index = 0;
	while (argv[2][index])
	{
		send_char(pid, argv[2][index]);
		index++;
	}
	send_char(pid, '\n');
	return (0);
}
