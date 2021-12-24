/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 13:59:59 by tkano             #+#    #+#             */
/*   Updated: 2021/12/24 13:59:59 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>

extern char **environ;

void    main(int argc, char *argv[])
{
    int file_fd;
    char    *cmd[2];

    if (argc != 2)
    {
        printf("Usage: %s file_name\n", argv[0]);
        exit(1);
    }
    file_fd = open(argv[1], O_RDONLY);
    if (file_fd < 0)
    {
        perror("open");
        close(file_fd);
        exit(1);
    }
    close(0);
    dup(file_fd, 0);
    close(file_fd);
    cmd[0] = "/bin/wc";
    cmd[1] = NULL;

    execlp("wc", "wc", NULL);
}
