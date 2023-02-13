/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldoni <dbaldoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:18:05 by dbaldoni          #+#    #+#             */
/*   Updated: 2023/02/11 10:49:55 by dbaldoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	size_t	i;
	size_t	mult;

	mult = count * size;
	if (size && count != mult / size)
		return (NULL);
	p = malloc(mult);
	if (!p)
		return (NULL);
	i = 0;
	while (i < (mult))
	{
		*((char *) p + i) = 0;
		i++;
	}
	return (p);
}
