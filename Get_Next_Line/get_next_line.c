/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldoni <dbaldoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:18:37 by dbaldoni          #+#    #+#             */
/*   Updated: 2023/04/17 20:21:36 by dbaldoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_read(int fd)
{

int byte_read;
char *buffer;

buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));



byte_read = read(fd, buffer, BUFFER_SIZE);

    return(buffer);    
}

char	*get_next_line(int fd)
{

    ft_read(fd);

}

int main()
{

int fd;

    fd = open("test.txt", O_RDONLY);
printf("%s \n", get_next_line(fd));

}
