/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:48:28 by arcarval          #+#    #+#             */
/*   Updated: 2023/02/19 19:48:28 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sig_handler(int signum)
{
	//Return type of the handler function should be void
	printf("\nInside handler function\n");
}

int	main(int argc, char **argv)
{
	int pid = atoi(argv[1]);
	int	i = 0;

	printf("PID:%d\n", pid);
	if (argc != 3)
	{
		printf("Wrong parameters quantity! Where is the string?\n");
		printf("ARGC=%d\n", argc);
		return(0);
	}
	signal(SIGUSR1, sig_handler);
	while (1)
	{
		printf("%d : Inside main function\n", i++);
		kill(pid, SIGUSR1);
		sleep(1);  // Delay for 1 second
	}
	printf("ARGC=%d\n", argc);
	printf("ARGV[0]:%s\n", argv[0]);
	printf("ARGV[1]:%s\n", argv[1]);
	printf("ARGV[2]:%s\n", argv[2]);
	printf("ARGV[3]:%s\n", argv[3]);
	return (0);
}
