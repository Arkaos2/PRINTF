/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saibelab <saibelab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 13:32:54 by saibelab          #+#    #+#             */
/*   Updated: 2025/05/27 15:13:16 by saibelab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef void	(*t_fonction)(va_list, int *);

typedef struct t_t_conversion
{
	char		c;
	t_fonction	f;
}	t_conversion;

void			ft_putchar(char c, int *count);
void			ft_putnbr(int n, int *count);
void			ft_putstr(char *str, int *count);
void			print_decimal(va_list param, int *count);
void			putnbrhexa_low(unsigned long n, int *count);
void			putnbrhexa_up(unsigned long n, int *count);
void			print_string(va_list param, int *count);
void			print_char(va_list param, int *count);
void			unsigned_putnbr(unsigned int n, int *count);
void			print_unsigned(va_list param, int *count);
void			print_percent(va_list param, int *count);
void			print_hex_lower(va_list param, int *count);
void			print_hex_upper(va_list param, int *count);
void			print_pointer(va_list param, int *count);

t_conversion	*init_table(void);
t_conversion	*find_key(char cle, t_conversion *table);

int				ft_printf(const char *str, ...);

#endif
