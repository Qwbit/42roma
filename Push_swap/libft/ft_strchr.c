/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldoni <dbaldoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:30:23 by dbaldoni          #+#    #+#             */
/*   Updated: 2023/11/03 16:05:19 by dbaldoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnchr(const char *str, int c)
{
	while (*str != '\0' && (char)c != *str)
		str++;
	if ((char)c == *str)
		return ((char *)str);
	return (0);
}
