/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:24:18 by pfalli            #+#    #+#             */
/*   Updated: 2024/02/13 15:01:38 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int fd;
	char *str;
	int count = 1;
	fd = open("example.txt", O_RDONLY);

	if (fd == -1)
	{
		printf("Error opening File!\n");
		return(1);
	}
	while ((str = get_next_line(fd)))
	{
		printf("[ line %d ] --> %s", count, str);
		free(str);
		count++;
	}
	printf("\n");
	close(fd);
	return(0);
}



//	int main() 
//	{
//	    char *line;
//	
//	    printf("Please enter a line of text:\n");
//	    line = get_next_line(0); 
//	    if (line != NULL) {
//	        printf("You entered: %s\n", line);
//	        free(line);
//	    } else {
//	        printf("Error reading line.\n");
//	    }
//	}


//	int main() {
//	    char *line;
//	
//	    line = (char *)malloc(* sizeof(char)); 
//	
//	    if (line == NULL) {
//	        fprintf(stderr, "Memory allocation failed.\n");
//	        return 1;
//	    }
//	
//	    printf("Write a line: ");
//	
//	    if (scanf("%s", line) != 1)
//		{
//	        fprintf(stderr, "Error reading input.\n");
//	        free(line);
//	        return 1;
//	    }
//	
//	    printf("This is the line: %s!!! OK\n", line);
//	
//	    free(line);
//	
//	    return 0;
//	}
