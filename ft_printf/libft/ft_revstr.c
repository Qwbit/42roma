/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldoni <dbaldoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:09:40 by dbaldoni          #+#    #+#             */
/*   Updated: 2023/03/06 21:55:00 by dbaldoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_rev_str(char *str)
{
	int		i;
	int		j;
	char	*str2;

	i = 0;
	j = ft_strlen(str);
	str2 = malloc(j + 1);
	j--;
	while (str[i])
		str2[i++] = str[j--];
	str2[i] = '\0';
	free (str);
	return (str2);
}
