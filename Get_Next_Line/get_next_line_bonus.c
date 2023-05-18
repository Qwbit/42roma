/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldoni <dbaldoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:18:37 by dbaldoni          #+#    #+#             */
/*   Updated: 2023/05/18 11:20:29 by dbaldoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_read(int fd, char **buffer)
{
	int	l;

	if (!buffer)
		return (0);
	if (!*buffer)
		*buffer = (char *)malloc(BUFFER_SIZE);
	if (!*buffer)
		return (0);
	l = read(fd, *buffer, BUFFER_SIZE);
	if (l < 0)
		return (l);
	if (l < BUFFER_SIZE)
		(*buffer)[l] = 0;
	return (0);
}

char	*ft_split_first(char *s1, char c)
{
	char	*s2;
	int		i;
	int		j;
	int		k;

	i = 0;
	while (i < BUFFER_SIZE && s1[i] && s1[i] != c)
		i++;
	if (i < BUFFER_SIZE && s1[i] == c)
		i++;
	s2 = NULL;
	if (i > 0)
		s2 = malloc(i + 1);
	if (!s2)
		return (NULL);
	s2[i] = 0;
	j = 0;
	k = 0;
	while (j < i)
		s2[j++] = s1[k++];
	j = 0;
	while (k < BUFFER_SIZE && s1[k])
		s1[j++] = s1[k++];
	s1[j] = 0;
	return (s2);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*new_line;
	int			r;

	r = 0;
	if (!buffer || !*buffer)
		r = ft_read(fd, &buffer);
	if (r < 0 && buffer)
		free(buffer);
	if (r < 0)
		buffer = 0;
	if (!buffer)
		return (NULL);
	new_line = ft_split_first(buffer, '\n');
	if (new_line && !ft_strchr_pos(new_line, '\n', 0))
		new_line = ft_strjoin(new_line, get_next_line(fd));
	if (buffer && (!*buffer || !new_line))
	{
		free(buffer);
		buffer = NULL;
	}
	return (new_line);
}
