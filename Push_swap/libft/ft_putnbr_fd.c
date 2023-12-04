/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldoni <dbaldoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 07:38:22 by dbaldoni          #+#    #+#             */
/*   Updated: 2023/02/10 09:20:41 by dbaldoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int				i;
	int				slot_digits[100];
	unsigned int	nbr;

	if (n == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	nbr = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = -n;
	}
	i = 0;
	while (nbr > 0)
	{
		slot_digits[i] = nbr % 10;
		nbr /= 10;
		i++;
	}
	while (i > 0)
		ft_putchar_fd(slot_digits[--i] + '0', fd);
}
