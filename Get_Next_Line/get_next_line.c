/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbaldoni <dbaldoni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 19:18:37 by dbaldoni          #+#    #+#             */
/*   Updated: 2023/05/04 03:07:35 by dbaldoni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *ft_read(int fd)
{
    
    
    char *buffer;
    
    buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if (!buffer)
        return(NULL);    
    read(fd, buffer, BUFFER_SIZE);
    buffer[BUFFER_SIZE] = '\0';
    return (buffer);
}

char *get_new_line(int fd);

char *ft_relocate(int *i, int *pos, char **stack, int fd)
{

int backup_set;
int j;
char *backup;

backup = NULL;
free(backup);

j = ft_strrchr(*stack, '\n');
backup_set = (ft_strlen(*stack) - j);
j = 0;
if ( backup_set <= 1)
    {
        *i = 0;
        *pos = 0;
        free(*stack);
        *stack = NULL;
        *stack = ft_read(fd);
        return(get_new_line(fd));
    }
else
    {
        backup = malloc(sizeof(char) * backup_set + 1);
        while((*stack)[*i])
        {

            backup[j] = (*stack)[*i];
            *i = *i + 1;         
            j++;
        }
    }
 
    backup[j] = '\0';
    free(*stack);

    *stack = ft_strjoin(backup,ft_read(fd));
    free(backup);
    *i = 0;
    *pos = 0;
    return(get_new_line(fd));
}

char *get_new_line(int fd)
{
static char *stack;
char *test;
char *new_line;
static int i;
static int pos;

int j;

test = stack;
j = 0;
i = i + 0;
pos = pos + 0;
if (!stack)
{
    stack = ft_strdup(ft_read(fd));
}
test = stack;
if (ft_strchr_pos(stack, '\n', i))
    pos = ft_chrpos(stack, '\n', i) + 1;
else
    return(ft_relocate(&i, &pos, &stack, fd));
test = stack;
new_line = malloc(sizeof(char) * ((pos - i) + 1));

while(i < pos)
    {
        new_line[j] = stack[i];
        i++;
        j++;
    }
    new_line[j] = '\0';
return(new_line);
}



char *get_next_line(int fd)
{
  

  
return(get_new_line(fd));
    
}

// int main()
// {

//     int fd;
//      fd = open("test2.txt", O_RDONLY);
     
//      printf("%s", get_next_line(fd));



// }
