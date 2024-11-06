/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 17:58:40 by migumar2          #+#    #+#             */
/*   Updated: 2024/09/24 18:28:45 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_content(char **content)
{
	int	i;

	i = 0;
	while (content[i])
	{
		free(content[i]);
		i++;
	}
	free(content);
}

void	free_game(t_game *game)
{
	if (game)
	{
		if (game->map)
			free_content(game->map);
		free(game->path_north);
		free(game->path_south);
		free(game->path_west);
		free(game->path_east);
		free(game->player);
	}
}

void	error(char *message, char **content, t_game *game)
{
	if (content)
		free_content(content);
	free_game(game);
	write(2, "Error\n", 7);
	if (message)
	{
		write(2, message, ft_strlen(message));
		write(2, "\n", 1);
	}
	exit(1);
}
