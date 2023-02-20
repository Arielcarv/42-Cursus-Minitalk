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

int	main(int argc, char **argv)
{
	if (argc != 1)
	{
		printf("ARGC=%d\n", argc);
	}
	printf("ARGV[0]:%s\n", argv[0]);
	printf("ARGV[1]:%s\n", argv[1]);
	printf("ARGV[2]:%s", argv[2]);
	return (0);
}
