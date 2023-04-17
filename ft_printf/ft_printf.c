/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldoni <dbaldoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 09:54:38 by dbaldoni          #+#    #+#             */
/*   Updated: 2023/03/06 22:05:29 by dbaldoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

int	ft_print_char(int c)
{
	write(1, &c, 1);
	return (1);
}

//------------------------------

int	ft_print_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str && str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_print_percent(void)
{
	int	c;

	c = 37;
	return (write(1, &c, 1));
}

int	ft_sort(va_list args, const char s)
{
	int	position;

	position = 0;
	if (s == 'c')
		position += (char)ft_print_char(va_arg(args, int));
	else if (s == 's')
		position += ft_print_str(va_arg(args, char *));
	else if (s == 'p')
		position += ft_print_pointer(va_arg(args, unsigned long long));
	else if (s == 'd')
	{
		position += ft_print_num(va_arg(args, int));
	}
	else if (s == 'i')
		position += ft_print_num(va_arg(args, int));
	else if (s == 'u')
		position += ft_print_unsigned(va_arg(args, unsigned int));
	else if (s == 'x')
		position += ft_print_hex((va_arg(args, unsigned long long)), 'x');
	else if (s == 'X')
		position += ft_print_hex((va_arg(args, unsigned long long)), 'X');
	else if (s == '%')
		position += ft_print_percent();
	return (position);
}

//---------------------------------

int	ft_printf(const char *test, ...)
{
	int		i;
	int		position;
	va_list	args;

	position = 0;
	va_start(args, test);
	i = 0;
	while (test[i])
	{
		if (test[i] == '%')
		{
			position += ft_sort(args, test[i + 1]);
			i++;
		}
		else
			position += ft_print_char(test[i]);
		i++;
	}
	va_end(args);
	return (position);
}
