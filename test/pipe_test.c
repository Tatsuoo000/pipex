/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 15:02:10 by tkano             #+#    #+#             */
/*   Updated: 2021/12/24 15:02:10 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int pipe_fd[2];

void    do_child()
{
    char    *p = "Heello, dad!!\n";

    printf("this is child.\n");
    close(pipe_fd[0]);
    close(1);
	dup2(pipe_fd[1], 1);
	close(pipe_fd[1]);
	while (*p)
		putchar(*p++);
}

void    do_parent()
{
	char	c;
	int		count;
	int		status;

	printf("this is parent.\n");
	close(pipe_fd[1]);
	close(0);
	dup2(pipe_fd[0], 0);
	close(pipe_fd[0]);
	while ((c = getchar()) != EOF)
		putchar(c);
	if (wait(&status) < 0)
	{
		perror("wait");
		exit(1);
	}
}

void    main()
{
    int child;

    if (pipe(pipe_fd) < 0)
    {
        perror("pipe");
        exit(1);
    }
    if ((child = fork()) < 0)
    {
        perror("fork");
        exit(1);
    }
    if (child)
        do_parent();
    else
        do_child();
}
