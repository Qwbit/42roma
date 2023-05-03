/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldoni <dbaldoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 19:46:39 by dbaldoni          #+#    #+#             */
/*   Updated: 2023/05/03 20:55:52 by dbaldoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*p;

	i = 0;
	while (s1[i])
		i++;
	p = malloc(i + 1);
	if (!p)
		return (0);
	i = 0;
	while (s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = 0;
	return (p);
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

int	ft_strrchr(char *s, int c)
{
	int		i;
	
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
		{
			return (i);
		}
		i--;
	}
	return (0);
}

int	ft_strchr_pos(char *s1, char c, int i)
{
	
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

int ft_chrpos(char *s1, char c, int i)
	{
	
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