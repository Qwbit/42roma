/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldoni <dbaldoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 14:32:13 by dbaldoni          #+#    #+#             */
/*   Updated: 2022/09/29 18:38:03 by dbaldoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive(int index, int n1, int n2)
{
	if (index == 0)
		return (0);
	if (index == 1)
		return (n2);
	if (index > 1)
		return (ft_recursive(index - 1, n2, n1 + n2));
	return (-1);
}

int	ft_fibonacci(int index)
{
	return (ft_recursive(index, 0, 1));
}
/*
int main()
{
	printf ("%d", ft_fibonacci(7));
}*/
