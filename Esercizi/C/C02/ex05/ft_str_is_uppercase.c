/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldoni <dbaldoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:28:04 by dbaldoni          #+#    #+#             */
/*   Updated: 2022/09/22 01:37:54 by dbaldoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    <stdio.h>

int	ft_str_is_uppercase(char *str)
{
	int	i;
	int	n;

	i = 0;
	n = 1;
	while (str[i])
	{
		if (str[i] < 'A' || str[i] > 'Z')
		{
			n = 0;
		}
		i++;
	}
	return (n);
}
