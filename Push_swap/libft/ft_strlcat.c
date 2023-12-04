/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldoni <dbaldoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:17:46 by dbaldoni          #+#    #+#             */
/*   Updated: 2023/02/02 04:31:25 by dbaldoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	s_len;
	size_t	d_len;

	if (!size)
		return (ft_strlen(src));
	if (!dest && !src)
		return (0);
	s_len = ft_strlen(src);
	d_len = ft_strlen(dest);
	i = 0;
	if (d_len >= size || size == 0)
		return (s_len + size);
	while (src[i] != '\0' && (d_len + i + 1 < size))
	{
		dest[d_len + i] = src[i];
		i++;
	}
	dest[d_len + i] = '\0';
	return (d_len + s_len);
}
