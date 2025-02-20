/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayelasef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:27:20 by ayelasef          #+#    #+#             */
/*   Updated: 2024/11/13 00:39:54 by ayelasef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(unsigned long nb, char *hex)
{
	int	count;

	count = 0;
	if (nb < 16)
	{
		count += print_char(hex[nb]);
		return (count);
	}
	else
		count += print_hex(nb / 16, hex);
	count += print_hex(nb % 16, hex);
	return (count);
}
