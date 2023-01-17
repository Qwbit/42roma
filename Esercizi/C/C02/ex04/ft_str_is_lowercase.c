/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldoni <dbaldoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:17:35 by dbaldoni          #+#    #+#             */
/*   Updated: 2022/09/22 01:37:53 by dbaldoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    <stdio.h>

int	ft_str_is_lowercase(char *str)
{
	int	i;
	int	n;

	i = 0;
	n = 1;
	while (str[i])
	{
		if (str[i] < 'a' || str[i] > 'z')
		{
			n = 0;
		}
		i++;
	}
	return (n);
}
