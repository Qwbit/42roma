/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldoni <dbaldoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:58:36 by dbaldoni          #+#    #+#             */
/*   Updated: 2023/03/09 03:30:01 by dbaldoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdio.h>

long long	ft_len_decnum(long long n)
{
	long	i;
	long	nbr;

	if (n <= 0)
		i = 1;
	else
		i = 0;
	nbr = n;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

char	*ft_dectoa(long long n)
{
	int		num;
	int		i;
	char	*str;

	str = malloc(((ft_len_decnum(n) + 1)));
	i = 0;
	if (n == 0)
		str[i++] = '0';
	if (n < 0)
		n = n * -1;
	while (n > 0)
	{
		num = n % 10;
		if (num < 10)
		{
			n = n / 10;
			str[i++] = num + 48;
		}
	}
	str[i] = '\0';
	str = ft_rev_str(str);
	return (str);
}

int	ft_print_num(long long n)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_dectoa(n);
	if (n < 0)
		write(1, "-", 1);
	while (str[i])
		write(1, &str[i++], 1);
	free(str);
	if (n < 0)
		++i;
	return (i);
}

int	ft_print_unsigned(long long n)
{
	int		i;
	char	*str;

	i = 0;
	str = ft_dectoa(n);
	while (str[i])
		write(1, &str[i++], 1);
	ft_bzero(str, ft_strlen(str));
	free(str);
	return (i);
}
