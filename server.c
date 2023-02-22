/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:05:49 by arcarval          #+#    #+#             */
/*   Updated: 2023/02/19 16:05:55 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
//signal macros and kill() prototype
#include <signal.h>

void	handle_signal(int signal)
{
	printf("Inside the handler. Signal number:%d\n", signal);
	return ;
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i = 0;

	(void)argv;
	if (argc != 1)
	{
		printf("Error!\n");
		return (0);
	}
	pid = getpid();
	while (1)
	{
		printf("%d: LOOP. PID Process: %d\n", i++, pid);
		signal(SIGUSR1, handle_signal);
		sleep(1);
	}
	printf("PID: %d", pid);
	return(0);
}
