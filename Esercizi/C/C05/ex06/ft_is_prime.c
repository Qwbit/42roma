/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldoni <dbaldoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 18:29:04 by dbaldoni          #+#    #+#             */
/*   Updated: 2022/09/29 18:48:08 by dbaldoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_prime(int nb)
{
	int	i;
	int	count;

	i = 1;
	count = 0;
	if (nb == 0 || nb == 1)
		return (0);
	if (nb == 2147483647)
		return (1);
	while (i <= nb)
	{
		if ((nb % i) == 0)
			count ++;
		i++;
	}
	if (count == 2)
		return (1);
	return (0);
}
