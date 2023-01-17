/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldoni <dbaldoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 19:46:49 by dbaldoni          #+#    #+#             */
/*   Updated: 2022/09/22 01:38:00 by dbaldoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcapitalize(char *str)
{

	int	i;
	int	j;
	char	test;
	char	test1;
	i = 0;
	j = 0;
	while (str[i])
	{
		test = str[i];
		if (str[i] >= 'a' && str[i] <= 'z' && str[i])
		{
			str[i] = str[i] -= 32;
		}
		while (j == 0) 
		{
			test = str[i];
			i++;
			test1 = str[i];
			if (str[i] < 'A' || (str[i] > 'Z' && str[i] < 'a') || str[i] > 'z')
			{
				j = 1;   
			}
		}
		j = 0;
		i++;
	}

	return (str);

}
