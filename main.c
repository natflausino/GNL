/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbarreir <nbarreir@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 22:35:23 by nbarreir          #+#    #+#             */
/*   Updated: 2021/03/07 00:06:33 by nbarreir         ###   ########.fr       */
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
    int        get_next;

    get_next = 1;

    fd = open("oi.txt", O_RDONLY);

    while (get_next > 0)
    {
        get_next = get_next_line(fd, &line);
        printf("%s\n", line);
        free(line);
    }
    close(fd);
    return (0);
}
