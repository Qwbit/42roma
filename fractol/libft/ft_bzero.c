/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldoni <dbaldoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 00:00:48 by dbaldoni          #+#    #+#             */
/*   Updated: 2023/01/24 19:40:58 by dbaldoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *buffer, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		((unsigned char *)buffer)[i] = '\0';
		i++;
	}
}
