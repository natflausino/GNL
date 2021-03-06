/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarreir <nbarreir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 22:35:23 by nbarreir          #+#    #+#             */
/*   Updated: 2021/03/06 01:00:06 by nbarreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "get_next_line.h"

int    main(void)
{
    char    *line;
    int        fd;
    //int        get_next1;

   // get_next1 = 1;

    fd = open("oi.txt", O_RDONLY);

    //while (get_next1 > 0)

    get_next_line(fd, &line);
    printf("%s\n", line);
    free(line);

    printf("ola\n\n");
   /*
    while (get_next2 > FT_EOF && get_next1 >FT_EOF)
    {
        get_next1 = get_next_line(fd[0], &line);
        printf("%s\n", line);
        free(line);

        get_next2 = get_next_line(fd[1], &line);
        printf("%s\n", line);
        free(line);
    }
    */
    close(fd);
    return (0);
}
