/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldoni <dbaldoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:18:37 by dbaldoni          #+#    #+#             */
/*   Updated: 2023/04/24 23:07:33 by dbaldoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_read(int fd)
{

    int byte_read;
    char *buffer;

    buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    byte_read = read(fd, buffer, BUFFER_SIZE);
    return (buffer);
}

char *print_string(int fd)
{

    int len;
    int i;
    char *string;
    char *short_string;

    len = 0;
    i = 0;

    string = ft_read(fd);

    while (string && string[len])
    {
        if (string[len] == '\n')
            break;
        len++;
        
    }
    //printf("%d",len);
    short_string = malloc(sizeof(char) * (len));

    while (i <= len)
    {

        short_string[i] = string[i];
        i++;
    }

    short_string[i] = '\0';
    return (short_string);
}

char *get_next_line(int fd)
{
    return (print_string(fd));
}

int main()
{

    int fd;

    fd = open("test.txt", O_RDONLY);
    printf("%s", get_next_line(fd));
   //get_next_line(fd);
}
