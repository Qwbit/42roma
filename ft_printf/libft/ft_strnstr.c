/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldoni <dbaldoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:17:10 by dbaldoni          #+#    #+#             */
/*   Updated: 2023/02/02 02:14:18 by dbaldoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *hays, const char *needle, size_t len)
{
	int		c;
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)hays);
	if ((!needle && !hays) || !len)
		return (0);
	c = needle[0];
	while (hays[i])
	{
		if (hays[i] == c)
		{
			j = 0;
			while (hays[i + j] && hays[i + j] == needle[j] && i + j < len)
			{
				j++;
			}
			if (j == ft_strlen(needle))
				return ((char *) & (hays[i]));
		}
		i++;
	}
	return (0);
}
