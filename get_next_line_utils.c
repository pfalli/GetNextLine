/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:19:08 by pfalli            #+#    #+#             */
/*   Updated: 2024/02/07 17:12:11 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//locate the first occurence c in the string, in this case a check for '\n' inside the buffer!!!!
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

// new strign in a new allocated string
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

// extract a substrign from another string
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*arr;
	size_t	len_s;
	size_t	i;

	if (s == NULL)
		return (NULL);
	len_s = ft_strlen(s);
	if (start > len_s)
		return (ft_strdup(""));
	if (start + len > len_s)
		len = len_s - start;
	arr = (char *)malloc(len + 1);
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		arr[i] = s[start + i];
		i++;
	}
	arr[i] = 0;
	return (arr);
}

// join 2 string inside a new string
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

//	char	*ft_strjoin(char const *s1, char const *s2)
//	{
//	    char	*joined;
//	    int		i, j;
//	
//	    if (!s1 || !s2)
//	        return (NULL);
//	    joined = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
//	    if (!joined)
//	        return (NULL);
//	    i = 0;
//	    while (s1[i])
//	    {
//	        joined[i] = s1[i];
//	        i++;
//	    }
//	    j = 0;
//	    while (s2[j])
//	    {
//	        joined[i + j] = s2[j];
//	        j++;
//	    }
//	    joined[i + j] = '\0';
//	    return (joined);
//	}