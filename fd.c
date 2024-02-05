/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfalli <pfalli@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 14:07:48 by pfalli            #+#    #+#             */
/*   Updated: 2024/02/05 14:08:00 by pfalli           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// example of static variable
//--------------------------------------
//  int count()
//  {
//      static int count = 0;
//      count++;
//      return(count);
//  }
//  
//  int main(void)
//  {
//      printf("%d", count());
//      printf("%d", count());
//      printf("%d", count());
//      return(0);
//  }

int main()
{
    int fd;
    char buf[200];
    int chars_read;
    
    fd = open("example.txt", O_RDONLY); 

    // char *get_next_line

    while((chars_read = read(fd, buf, 8)))
    {
        buf[chars_read] = 0;
        printf("%s\n", buf);
    }
}