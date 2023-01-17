/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldoni <dbaldoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 22:48:59 by dbaldoni          #+#    #+#             */
/*   Updated: 2022/09/29 22:59:56 by dbaldoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	result;

	i = power;
	result = nb;
	if (power == 0)
		return (1);
	while (i != 1)
	{
		result = result * nb;
		i--;
	}
	return (result);
}
/*
int main()
{
	printf("%d", ft_iterative_power(2, -4));
}*/
