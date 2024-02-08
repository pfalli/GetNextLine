/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:24:18 by pfalli            #+#    #+#             */
/*   Updated: 2024/02/08 15:45:07 by pfalli           ###   ########.fr       */
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