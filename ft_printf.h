/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saibelab <saibelab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 13:32:54 by saibelab          #+#    #+#             */
/*   Updated: 2025/05/23 15:43:35 by saibelab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef void (*fonction)(va_list);

typedef struct t_conversion
{
	char	c;
	fonction	f;
}	conversion;

void ft_putchar(char c);
void ft_putnbr(int n);
void ft_putstr(char *str);
void print_decimal(va_list param);
void putnbrhexa_low(int n);
void putnbrhexa_up(int n);
void print_string(va_list param);
void print_char(va_list param);
void unsigned_putnbr(unsigned int n);
void print_unsigned(va_list param);
void print_percent(va_list param);
void print_hex_lower(va_list param);
void print_hex_upper(va_list param);

conversion	*init_table(void);
conversion	*find_key(char cle, conversion *table);

int	ft_printf(const char *str, ...);
#endif


