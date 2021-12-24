/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 11:56:47 by tkano             #+#    #+#             */
/*   Updated: 2021/12/24 11:56:47 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

extern char **environ;

void    main()
{
    char    *argv[2];

    argv[0] = "/bin/ls";
    //argv[1] = "/";
    argv[1] = NULL;

    execve(argv[0], argv, environ);
    printf("env: %s", environ[0]);
}
