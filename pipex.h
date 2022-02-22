/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebouabba <ebouabba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 19:16:05 by ebouabba          #+#    #+#             */
/*   Updated: 2022/02/20 19:11:46 by ebouabba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct pipex
{
	int		i;
	pid_t	pid1;
	pid_t	pid2;
	char	**list_path;
	char	**cmd1;
	char	**cmd2;
	char	*path_cmd1;
	char	*path_cmd2;
	char	*path;
	char	*check;
	char	**envp;
	char	**argv;
	int		fds[2];
	int		file1;
	int		file2;
}t_list;

int		main(int ac, char **av, char **envp);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strlen(const char *str);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, int n);
char	*ft_strnstr(const char *haystack, char *needle, int len);
char	*ft_substr(char const *s, int start, int len);
char	*return_path(char **envp);
char	*check_command(char **list_cmd, char *av);
void	exceve_cmd(t_list pipex);
void	check_error(char *str);
void	ft_free_split(char	**tmp);

#endif
