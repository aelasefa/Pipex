/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayelasef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 19:34:52 by ayelasef          #+#    #+#             */
/*   Updated: 2024/11/12 20:26:43 by ayelasef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_add(void *n, char *hex)
{
	int				count;
	unsigned long	nb;

	count = 0;
	nb = (unsigned long)n;
	count += print_string("0x");
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
