/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouabba <ebouabba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 22:07:02 by ebouabba          #+#    #+#             */
/*   Updated: 2022/02/20 19:24:47 by ebouabba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*return_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", ft_strlen(envp[i])))
			return (envp[i] + 5);
		i++;
	}
	return (0);
}
