/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcarval <arcarval@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 15:38:43 by arcarval          #+#    #+#             */
/*   Updated: 2022/11/16 23:46:16 by arcarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int caracter)
{
	if ((caracter >= 'A' && caracter <= 'Z')
		|| (caracter >= 'a' && caracter <= 'z'))
		return (1);
	return (0);
}
