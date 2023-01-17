/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldoni <dbaldoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:33:50 by dbaldoni          #+#    #+#             */
/*   Updated: 2022/09/22 01:37:56 by dbaldoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    <stdio.h>

int	ft_str_is_printable(char *str)
{
	int		i;
	int		n;
	char	c;

	i = 0;
	n = 1;
	while (str[i])
	{
		c = str[i];
		if (str[i] <= 31 || c == 127)
		{
			n = 0;
		}
		i++;
	}
	return (n);
}
