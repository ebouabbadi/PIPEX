/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouabba <ebouabba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 22:42:27 by ebouabba          #+#    #+#             */
/*   Updated: 2022/02/20 19:12:53 by ebouabba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*command(char *path, char *av)
{
	t_list	pipex;
	int		i;

	i = 0;
	pipex.check = ft_strjoin(path, "/");
	pipex.path = ft_strjoin(pipex.check, av);
	return (pipex.path);
}

char	*check_command(char **list_cmd, char *av)
{
	t_list	pipex;
	int		i;

	i = 0;
	while (list_cmd[i])
	{
		pipex.check = command(list_cmd[i], av);
		if (access(pipex.check, F_OK) == 0)
			return (pipex.check);
		i++;
	}
	check_error("Error: command not found\n");
	return (NULL);
}
