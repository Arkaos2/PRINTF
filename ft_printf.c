/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saibelab <saibelab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 13:32:58 by saibelab          #+#    #+#             */
/*   Updated: 2025/05/23 15:54:06 by saibelab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>


conversion	*init_table(void)
{
	static	conversion table[] = {
		{'d', print_decimal},
		{'s', print_string},
		{'i', print_decimal},
		{'c', print_char},
		{'u', print_unsigned},
		{'x', print_hex_lower},
		{'X', print_hex_upper},
		//{'p', print_pointer},
		{'%', print_percent},
		{'\0', NULL}
	};
	return (table);
}
conversion	*find_key(char cle, conversion *table)
{
	int	i;

	i = 0;
	while (table[i].c)
	{
		if (table[i].c == cle)
			return (&table[i]);
		i++;
	}
	return (NULL);
}

int	ft_printf(const char *str, ...)
{
	int	i;
	va_list param;
	conversion *table;
	conversion	*conv;

	i = 0;
	table = init_table();
	va_start (param, str);
	while(str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			i++;
			conv = find_key(str[i], table);
			if (conv && conv->f)
				conv->f(param);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
	va_end(param);
	return (0);
}

int main()
{
	int c = 27;
	printf("%x \n", c);
}
