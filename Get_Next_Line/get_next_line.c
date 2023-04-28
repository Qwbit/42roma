/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldoni <dbaldoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:18:37 by dbaldoni          #+#    #+#             */
/*   Updated: 2023/04/28 03:24:25 by dbaldoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_read(int fd)
{
    
    int byte_read;
    char *buffer;
    
    buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
        return(NULL);    
    byte_read = read(fd, buffer, BUFFER_SIZE);

    
    return (buffer);
}

char *ft_print_string(char *copy)
{
int i;
char *print;
i = 0;
print = NULL;

if (ft_strchr(copy, '\n') == 1)
    {
        print = malloc(sizeof(char) * (ft_chrpos(copy, '\n') + 1));
        while (i <= ft_chrpos(copy, '\n'))
            {
                print[i] = copy[i];
                i++;
            }
            print[i] = '\0';
            return(print);
    }

return(NULL);
}

char *ft_copy(char *copy)
    {
        int i;
        char *copy2;    
        i = ft_chrpos(copy, '\n');  
        copy2 = malloc(sizeof(char) * (ft_strlen(copy) - i));
        while(copy[i])
            {
                copy2[i] = copy[i];
                i++;
            }
        free(copy);
        copy = copy2;
        return(copy);        
    }

char *ft_backup(char *copy, char *copy2, char *backup)
{
    int len;
    int i;
    int j;
    i = 0;
    j = 0;
    len = ft_strlen(backup);
    free(copy2);
    copy2 = copy;
    free(copy);
    copy = malloc(sizeof(char) * (len + ft_strlen(copy2)));
    
    while(backup[i])
        {
            copy[i] = backup[i];
            i++;
        }
   
    while(copy2[j])
        {
            copy[i] = copy2[j];
            i++;
            j++;
        }
    free(backup);
    return(copy);
}




char *get_next_line(int fd)
{
  
return(print);
    
}

int main()
{

    int fd;

    fd = open("test.txt", O_RDONLY);
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
    printf("%s", get_next_line(fd));
}
