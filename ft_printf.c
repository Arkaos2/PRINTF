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

void	*init_table(conversion *table)
{
	table[0].c = 'd';
	table[0].f = ;
	table[1].c = 's';
	table[1].f = ;
	table[2].c = 'c';
	table[2].f = ;
	table[3].c = 'u';
	table[3].f = ;
	table[4].c = 'x';
	table[4].f = ;
	table[5].c = 'X';
	table[5].f = ;
	table[6].c = 'p';
	table[6].f = ;
	table[7].c = '%';
	table[7].f = ;
	table[8].c = '\0';
	table[8].f = 0;
}

conversion	*choosen(char cle, conversion *table)
{
	int	i;

	i = 0;
	while (table[i].c)
	{
		if (table[i].c == cle)
		{
			return (&table[i]);
		}
		i++;
	}
	return (NULL);
}

int	ft_printf(const char *str, ...)
{
	va_list param;


	va_start(param, str);

}
