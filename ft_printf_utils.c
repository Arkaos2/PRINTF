/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saibelab <saibelab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 13:32:50 by saibelab          #+#    #+#             */
/*   Updated: 2025/05/23 13:45:56 by saibelab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void putnbrhexa_low(int nb)
{
	char *base;
	long n = (long)nb;

	base = "0123456789abcdef";
	if(n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if(n > 16)
	{
		putnbrhexa_low(n / 16);
		putnbrhexa_low(n % 16);
	}
	if(n < 16)
		ft_putchar(base[n]);

}
void putnbrhexa_up(int nb)
{
	char *base;
	long n = (long)nb;

	base = "0123456789ABCDEF";
	if(n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if(n > 16)
	{
		putnbrhexa_up(n / 16);
		putnbrhexa_up(n % 16);
	}
	if(n < 16)
		ft_putchar(base[n]);

}

void print_hex_upper(va_list param)
{
	int n = va_arg(param, int);
	putnbrhexa_up(n);
}
void print_hex_lower(va_list param)
{
	int n = va_arg(param, int);
	putnbrhexa_low(n);
}

void ft_putnbr(int n)
{
	if (n == -2147483648)
		write(1, "-2147483648", 11);
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n > 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	if (n < 10)
		ft_putchar(n + '0');
}

void unsigned_putnbr(unsigned int n)
{
	if (n > 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	if (n < 10)
		ft_putchar(n + '0');
}
void print_percent(va_list param)
{
	(void)param;
	ft_putchar('%');
}

void print_char(va_list param)
{
	char c = va_arg(param, int);
	ft_putchar(c);
}

void ft_putstr(char *str)
{
	int	i;

	i = 0;
	while(str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}
void print_unsigned(va_list param)
{
	unsigned int n;
	n = va_arg(param, unsigned int);
	unsigned_putnbr(n);
}

void print_string(va_list param)
{
	char *str;
	str = va_arg(param, char *);
	ft_putstr(str);
}

void print_decimal(va_list param)
{

	int	n;
	n = va_arg(param, int);
	ft_putnbr(n);
}
