/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldoni <dbaldoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 21:28:11 by dbaldoni          #+#    #+#             */
/*   Updated: 2022/09/29 22:57:02 by dbaldoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	res;

	res = 1;
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	else
	{
		while (nb > 0)
		{
			res *= nb;
			nb--;
		}
		return (res);
	}
}
