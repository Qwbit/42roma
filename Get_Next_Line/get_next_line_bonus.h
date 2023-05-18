/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldoni <dbaldoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:51:12 by dbaldoni          #+#    #+#             */
/*   Updated: 2023/05/18 11:24:40 by dbaldoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int		ft_chrpos(char *s1, char c, int i);
char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strchr_pos(char *s1, char c, int i);
size_t	ft_strlen(char *str);
void	*ft_free(char *s1, char *s2);
char	*ft_strdup(const char *s1);
int		ft_strrchr(char *s, int c);

#endif
