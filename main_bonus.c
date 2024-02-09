/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:11:56 by pfalli            #+#    #+#             */
/*   Updated: 2024/02/09 14:24:08 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int fd1, fd2;
	char *str;
	int count = 1;
	fd1 = open("example.txt", O_RDONLY);
    fd2 = open("example2.txt", O_RDONLY);

	if (fd1 == -1 || fd2 == -1)
	{
		printf("Error opening File!\n");
		return(1);
	}
	while ((str = get_next_line(fd1)))
	{
		printf("[ line %d ] --> %s", count, str);
		free(str);
		count++;
	}
    printf("\n");
    count = 1;
    while ((str = get_next_line(fd2)))
	{
		printf("[ line %d ] --> %s", count, str);
		free(str);
		count++;
	}
	printf("\n");
	close(fd1);
    close(fd2);
	return(0);
}
