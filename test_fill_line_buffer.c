/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_fill_line_buffer.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:16:24 by pfalli            #+#    #+#             */
/*   Updated: 2024/02/06 14:23:02 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
        if (c_read == 0)
        {
            break;
			printf("Break");
        }
        buffer[c_read] = 0; // now buffer stores the line and i have to store it in another string => left_c to return it in the original getnextline
        if(!left_c)
            left_c = ft_strdup(""); // to avoid memory leaks
        temp = left_c;
        left_c = ft_strjoin(temp, buffer); 
        free(temp);
        temp = NULL;
        if(ft_strchr(buffer, 'n')) // if it finds a new line it breaks the loop
            break;
    }
    return(left_c);
}

int main()
{
	char *buffer;
	char *left_c = NULL;
	int fd;
	char *result;
	
	fd = open("example.txt", O_RDONLY);
	
	buffer = (char *)malloc(BUFFER_SIZE + 1);
	result = fill_line_buffer(fd, left_c, buffer);
	
	printf("line => %s", result);
	
	free(buffer);
	free(result);
	close(fd);
	
	return(0);
}

//-----------------------------------------------------------------------------

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_len;
	char	*dest;
	int		i;
	int		x;

	total_len = (int)ft_strlen(s1) + (int)ft_strlen(s2);
	i = 0;
	x = 0;
	dest = malloc(total_len + 1);
	if (dest == 0)
		return (0);
	while (i < (int)ft_strlen(s1))
	{
		dest[i] = s1[i];
		i++;
	}
	while (x < (int)ft_strlen(s2))
	{
		dest[i] = s2[x];
		x++;
		i++;
	}
	dest[i] = 0;
	return (dest);
}


char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

char	*ft_strdup(char *s1)
{
	char			*dest;
	unsigned int	i;

	dest = (char *) malloc(ft_strlen(s1) + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

int	ft_strlen(const char *str)
{
	int	x;

	x = 0;
	while (str[x] != '\0')
	{
		x++;
	}
	return (x);
}