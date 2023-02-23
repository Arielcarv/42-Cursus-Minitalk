/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 20:15:11 by arcarval          #+#    #+#             */
/*   Updated: 2022/11/30 16:29:53 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int caracter)
{
	if (caracter >= ' ' && caracter <= '~')
		return (1);
	return (0);
}