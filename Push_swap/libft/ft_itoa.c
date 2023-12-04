/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldoni <dbaldoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 21:12:30 by dbaldoni          #+#    #+#             */
/*   Updated: 2023/02/10 09:16:22 by dbaldoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len_num(int n)
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

char	*ft_itoa(int n)
{
	long	nbr;
	long	len;
	char	*str;

	nbr = n;
	len = ft_len_num(n);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (n < 0)
	{
		nbr = -nbr;
		str[0] = '-';
	}
	while (nbr >= 10)
	{
		str[len--] = 48 + (nbr % 10);
		nbr /= 10;
	}
	str[len] = 48 + nbr;
	return (str);
}
