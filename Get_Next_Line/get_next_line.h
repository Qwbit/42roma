/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldoni <dbaldoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:51:12 by dbaldoni          #+#    #+#             */
/*   Updated: 2023/04/28 01:07:35 by dbaldoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strchr(char *s1, char c);
size_t	ft_strlen(char *str);
void	*ft_free(char *s1, char *s2);
size_t	ft_is_newline(char c);
int     ft_chrpos(char *s1, char c);
char    *ft_print_string(char *copy);
char    *ft_copy(char *copy);
char    *ft_backup(char *copy, char *copy2, char *backup);

#endif

