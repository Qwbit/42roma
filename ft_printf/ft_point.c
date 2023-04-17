/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_point.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldoni <dbaldoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 00:29:54 by dbaldoni          #+#    #+#             */
/*   Updated: 2023/02/28 01:05:58 by dbaldoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdio.h>

int	ft_hex_len_p(unsigned long long num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_put_hex_p(unsigned long long num, const char format)
{
	if (num >= 16)
	{
		ft_put_hex_p(num / 16, format);
		ft_put_hex_p(num % 16, format);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
		{
			if (format == 'x')
				ft_putchar_fd((num - 10 + 'a'), 1);
			if (format == 'X')
				ft_putchar_fd((num - 10 + 'A'), 1);
		}
	}
}

int	ft_print_hex_p(unsigned long long num, const char format)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_put_hex_p(num, format);
	return (ft_hex_len_p(num));
}

int	ft_print_pointer(unsigned long long n)
{
	int		i;
	char	buffer[2];

	buffer[0] = '0';
	buffer[1] = 'x';
	write(1, buffer, 2);
	i = ft_print_hex_p(n, 'x');
	return (i + 2);
}
