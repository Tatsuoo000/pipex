/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 23:57:36 by tkano             #+#    #+#             */
/*   Updated: 2021/12/24 16:54:46 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>

# define TRUE 1
# define FALSE 0
# define SUCCESS 0
# define ERROR -1
# define READ 0
# define WRITE 1

typedef struct s_cmd {
	char	*cmd;
	int		pipefd[2];
	int		pid;
}			t_cmd;

typedef struct s_info {
	char	*file1;
	char	*file2;
	t_cmd	**cmd;
	char	**env;
}			t_info;


#endif
