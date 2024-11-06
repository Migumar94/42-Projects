/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:47:24 by migumar2          #+#    #+#             */
/*   Updated: 2024/04/16 19:02:51 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (env[i][0] == 'P' && env[i][1] == 'A' && env[i][2] == 'T'
			&& env[i][3] == 'H' && env[i][4] == '=')
			return (ft_strjoin(env[i], ":."));
		i++;
	}
	return (PATH);
}

char	*find_exe(char **paths, char *comand)
{
	int		i;
	char	*aux;
	char	*path_comand;

	i = 0;
	while (paths[i])
	{
		aux = ft_strjoin(paths[i], "/");
		path_comand = ft_strjoin(aux, comand);
		free(aux);
		if (!access(path_comand, F_OK))
		{
			return (path_comand);
		}
		i++;
		free(path_comand);
	}
	if (!access(comand, F_OK))
		return (comand);
	return (NULL);
}

void	child(char **argv, int *p_fd, char **env)
{
	int		fd;
	char	*path;
	char	**paths;
	char	**comand;

	paths = ft_split(&find_path(env)[5], ':');
	comand = ft_spliter(argv[2]);
	if (argv[2][0] == '.')
		path = delete_slash(comand[0]);
	else
		path = find_exe(paths, comand[0]);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		write(2, "pipex: input: No such file or directory\n", 42);
		exit(1);
	}
	dup2(fd, 0);
	dup2(p_fd[1], 1);
	close(p_fd[0]);
	if (!access(path, F_OK) && access(path, X_OK))
		exit(126);
	exec(path, comand, paths, env);
}

void	parent(char **argv, int *p_fd, char **env)
{
	int		fd;
	char	*path;
	char	**paths;
	char	**comand;

	paths = ft_split(&find_path(env)[5], ':');
	comand = ft_spliter(argv[3]);
	if (argv[3][0] == '.')
		path = delete_slash(argv[3]);
	else
		path = find_exe(paths, comand[0]);
	fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		write(2, "pipex: input: No such file or directory\n", 42);
		exit (1);
	}
	dup2(fd, 1);
	dup2(p_fd[0], 0);
	close(p_fd[1]);
	if (!access(path, F_OK) && access(path, X_OK))
		exit (126);
	exec(path, comand, paths, env);
}

int	main(int argc, char **argv, char **env)
{
	int		fd[2];
	int		pid1;
	int		pid2;

	if (argc != 5)
		exit(1);
	if (pipe(fd) == -1)
		exit(1);
	pid1 = fork();
	if (pid1 == -1)
		exit(1);
	if (pid1 == 0)
		child(argv, fd, env);
	else
	{
		pid2 = fork();
		if (pid2 == -1)
			exit(1);
		if (pid2 == 0)
			parent(argv, fd, env);
	}
	return (0);
}
