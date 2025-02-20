/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayelasef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:52:54 by ayelasef          #+#    #+#             */
/*   Updated: 2024/11/12 19:08:13 by ayelasef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print(unsigned int nb)
{
	if (nb >= 0 && nb <= 9)
	{
		ft_putchar_fd(nb + 48, 1);
		return ;
	}
	else
		ft_print(nb / 10);
	ft_putchar_fd((nb % 10) + '0', 1);
}

static int	ft_count_nb(unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		i++;
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

int	print_unsigned(unsigned int nb)
{
	unsigned int	count;

	ft_print(nb);
	count = ft_count_nb(nb);
	return (count);
}
