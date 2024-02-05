/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:13:18 by pfalli            #+#    #+#             */
/*   Updated: 2024/02/05 14:43:18 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char *get_next_line(int fd)
{
    // checking the fd and memory allocation
    static char *left_c;
    char *line;
    char *buffer;
    int chars_read;

    buffer = (char *)malloc(BUFFER_SIZE + 1) *sizeof(char);
    if (buffer == NULL)
        return(NULL);
    if (fd < 0 || BUFFER_SIZE <= 0)
    {
        free(buffer);
        buffer = NULL;
        return(0);
    }
    if (buffer == NULL)
        return(NULL);
    // fill_line_buffer until \n o \0
    line = fill_line_buffer(fd,__x86_64__ , buffer);
    free(buffer);
    if(line == NULL)
        return(NULL);
    // set_line> return the line, storing the return value into the static variable
    

}

char *fill_line_buffer(int fd, char *left_c, char *buffer)
{
    int c_read = 1;
    char *temp;
    
    while(c_read > 0)
    {
        c_read = read(fd, buffer, BUFFER_SIZE);
        if (c_read == -1)
        {
            free(left_c);
            return(0);
        }
        if (c_read = 0)
        {
            break;
        }
        buffer[c_read] = 0; // now buffer stores the line and i have to store it in another string => left_c to return it in the original getnextline
        if(!left_c)
            left_c = ft_strdup(""); // empty string
        temp = left_c;
        left_c = ft_strjoin(temp, buffer); // now it's stored in left_c
        free temp;
        temp = NULL;
        if(ft_strchr(buffer, 'n')) // if it finds a new line it breaks the loop
            break;
    }
    return(left_c);
}


char *set_line(char *line)
{
    int x = 0;
    char *left_c;

    while ( line[x] != '\n')
    {
        x++;
    }
    if (line[x] == 0)
        return(0);
    left_c = ft_substr(line, x + 1, ft_strlen(line) - x );
    

}