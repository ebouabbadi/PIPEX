/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouabba <ebouabba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 19:15:47 by ebouabba          #+#    #+#             */
/*   Updated: 2022/02/20 20:28:13 by ebouabba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_split(char **tmp)
{
	int	i;

	if (!tmp)
		return ;
	i = -1;
	while (tmp[++i])
		free (tmp[i]);
	free(tmp);
}

void	check_error(char *str)
{
	ft_putstr_fd(str, 2);
	exit(1);
}

int	main(int ac, char **av, char **envp)
{
	t_list	pipex;

	if (ac != 5)
		check_error("Error: invalid number of arguments\n");
	pipex.argv = av;
	pipex.path = return_path(envp);
	pipex.list_path = ft_split(pipex.path, ':');
	pipex.cmd1 = ft_split(pipex.argv[2], ' ');
	pipex.cmd2 = ft_split(pipex.argv[3], ' ');
	pipex.path_cmd1 = check_command(pipex.list_path, pipex.cmd1[0]);
	pipex.path_cmd2 = check_command(pipex.list_path, pipex.cmd2[0]);
	pipe(pipex.fds);
	pipex.file1 = open(pipex.argv[1], O_RDONLY);
	if (pipex.file1 < 0)
		check_error("Error: cannot open file1\n");
	pipex.file2 = open(pipex.argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0000644);
	if (pipex.file2 < 0)
		check_error("Error: cannot open/create file2\n");
	exceve_cmd(pipex);
	wait(NULL);
	ft_free_split(pipex.list_path);
	ft_free_split(pipex.cmd1);
	ft_free_split(pipex.cmd2);
	return (0);
}
