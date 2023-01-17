/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldoni <dbaldoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 22:59:31 by dbaldoni          #+#    #+#             */
/*   Updated: 2022/09/29 22:59:58 by dbaldoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive(int nb, int power, int result)
{
	if (power == 0)
		return (1);
	if (power == 1)
		return (result);
	if (power >= 0)
		return (ft_recursive(nb, power - 1, result *= nb));
	return (0);
}

int	ft_recursive_power(int nb, int power)
{
	int	result;

	result = nb;
	return (ft_recursive(nb, power, result));
}
/*
int	main()
{
	printf("%d", ft_recursive_power(2, 5));
}*/
