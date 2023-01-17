/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldoni <dbaldoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 20:56:26 by dbaldoni          #+#    #+#             */
/*   Updated: 2022/09/27 20:33:58 by dbaldoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	int				i;
	int				slot_digits[100];
	unsigned int	nbr;

	if (nb == 0)
	{
		ft_putchar('0');
		return ;
	}
	nbr = nb;
	if (nb < 0)
	{
		ft_putchar('-');
		nbr = -nb;
	}
	i = 0;
	while (nbr > 0)
	{
		slot_digits[i] = nbr % 10;
		nbr /= 10;
		i++;
	}
	while (i > 0)
		ft_putchar(slot_digits[--i] + '0');
}

/*
int main()
{


ft_putnbr(429496729);
	

}
*/
