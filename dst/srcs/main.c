/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkano <tkano@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 23:59:20 by tkano             #+#    #+#             */
/*   Updated: 2021/12/24 17:01:39 by tkano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	error_check(int argc)
{
	if (argc < 5)
	{
		ft_putendl_fd("arguments error", 2);
		return (ERROR);
	}
	return (SUCCESS);
}

int	main(int argc, char **argv, char **env)
{
	t_info	*info;

	if (error_check(argc))
		return (ERROR);
	return (SUCCESS);
}
