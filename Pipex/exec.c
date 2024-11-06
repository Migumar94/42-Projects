/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:59:13 by migumar2          #+#    #+#             */
/*   Updated: 2024/04/16 18:22:06 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec(char *path, char **comand, char **paths, char **env)
{
	if (execve(path, comand, env) == -1)
	{
		error(comand[0]);
		free_list(comand);
		free(path);
		free_list(paths);
		exit (127);
	}
	free_list(comand);
	free(path);
	free_list(paths);
}
