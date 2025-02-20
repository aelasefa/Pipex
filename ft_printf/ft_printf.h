/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayelasef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 19:04:39 by ayelasef          #+#    #+#             */
/*   Updated: 2025/02/03 17:08:10 by ayelasef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdio.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	print_int(int nb);
int	print_string(char *s);
int	print_char(char c);
int	print_unsigned(unsigned int nb);
int	print_hex(unsigned long nb, char *hex);
int	print_add(void *n, char *hex);
#endif
