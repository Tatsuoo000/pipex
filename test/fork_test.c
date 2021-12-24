/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 11:21:32 by tkano             #+#    #+#             */
/*   Updated: 2021/12/24 11:21:32 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

void    do_child()
{
    printf("This is child(pid=%d).\n", getpid());
    exit(3);
}

void    main()
{
    int child;
    int status;

    if ((child = fork()) < 0)
    {
        perror("fork");
        exit(1);
    }
    if (child == 0)
        do_child();
    else
    {
        if (wait(&status) < 0)
        {
            perror("wait");
            exit (1);
        }
        printf("The child (pid=%d) existed with status (%d).\n", child, WEXITSTATUS(status));
    }
}
