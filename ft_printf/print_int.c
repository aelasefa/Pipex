/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayelasef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 09:58:56 by ayelasef          #+#    #+#             */
/*   Updated: 2024/11/12 19:07:45 by ayelasef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count_nb(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i++;
	else if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

int	print_int(int nb)
{
	int	count;

	if (nb == -2147483648)
	{
		ft_putnbr_fd(nb, 1);
		return (11);
	}
	count = ft_count_nb(nb);
	ft_putnbr_fd(nb, 1);
	return (count);
}
