/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exceve_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouabba <ebouabba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 23:48:56 by ebouabba          #+#    #+#             */
/*   Updated: 2022/02/20 20:43:44 by ebouabba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static	void	child_cmd1(t_list pipex)
{
	dup2(pipex.file1, 0);
	dup2(pipex.fds[1], 1);
	close(pipex.fds[0]);
	execve(pipex.path_cmd1, pipex.cmd1, NULL);
	check_error("Error: execve mistake\n");
	ft_free_split(pipex.cmd1);
	exit(1);
}

static	void	child_cmd2(t_list pipex)
{
	dup2(pipex.fds[0], 0);
	dup2(pipex.file2, 1);
	close(pipex.fds[1]);
	execve(pipex.path_cmd2, pipex.cmd2, NULL);
	check_error("Error: execve mistake\n");
	ft_free_split(pipex.cmd2);
	exit(1);
}

void	exceve_cmd(t_list pipex)
{
	pipex.pid1 = fork();
	if (pipex.pid1 < 0)
		check_error("Error: \n");
	if (pipex.pid1 == 0)
		child_cmd1(pipex);
	pipex.pid2 = fork();
	if (pipex.pid2 < 0)
		check_error("Error: \n");
	if (pipex.pid2 == 0)
		child_cmd2(pipex);
	close(pipex.fds[0]);
	close(pipex.fds[1]);
	close(pipex.file1);
	close(pipex.file2);
}
