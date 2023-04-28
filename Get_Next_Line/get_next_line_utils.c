/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldoni <dbaldoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 19:46:39 by dbaldoni          #+#    #+#             */
/*   Updated: 2023/04/27 03:20:05 by dbaldoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_is_newline(char c)
{
	if (c == '\n')
		return (1);
	return (0);
}

void	*ft_free(char *s1, char *s2)
{
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	return (NULL);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strchr(char *s1, char c)
{
	size_t	i;

	i = 0;
	if (!s1)
		return (0);
	while (s1[i])
	{
		if (s1[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int ft_chrpos(char *s1, char c)
	{
		size_t	i;

	i = 0;
	if (!s1)
		return (0);
	while (s1[i])
	{
		if (s1[i] == c)
		{
			return (i);
		}
		i++;
	}
	return (0);		
	}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	s2len;
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1)
	{
		s1 = malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	i = -1;
	j = 0;
	s2len = ft_strlen(s2);
	str = (char *)malloc (ft_strlen(s1) + s2len + 1);
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	while (j < s2len)
		str[i++] = s2[j++];
	str[i] = '\0';
	ft_free(s1, NULL);
	return (str);
}