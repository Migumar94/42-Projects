/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:22:05 by migumar2          #+#    #+#             */
/*   Updated: 2024/09/25 19:22:29 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	add_spaces(t_game *game, int max_length)
{
	int		i;
	int		j;
	char	*aux;

	i = 0;
	while (game->map[i])
	{
		j = ft_strlen2(game->map[i]);
		aux = ft_calloc((max_length + 1), sizeof (char));
		if (!aux)
			error("Error in memory allocation", NULL, game);
		ft_strlcpy(aux, game->map[i], max_length + 1);
		while (j < max_length)
		{
			aux[j] = ' ';
			j++;
		}
		free(game->map[i]);
		game->map[i] = ft_strdup(aux);
		i++;
		free(aux);
	}
}

void	fill_map(char **content, t_game *game)
{
	int	i;
	int	lines;
	int	max_length;
	int	j;

	max_length = 0;
	i = -1;
	while (content[++i])
	{
		if (content[i][0] == '1' || content[i][0] == ' ')
			break ;
	}
	lines = game->rows - i;
	game->map = ft_calloc((lines + 1), sizeof (char *));
	if (!game->map)
		error("Error in memory allocation", content, game);
	j = i;
	while (i < game->rows)
	{
		game->map[i - j] = ft_substr(content[i], 0, ft_strlen(content[i]));
		if (ft_strlen2(game->map[i - j]) > max_length)
			max_length = ft_strlen2(game->map[i - j]);
		i++;
	}
	add_spaces(game, max_length);
}

void	fill_flood(char **map, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == ' ')
			{
				if (map[i][j + 1] == '0' || (j > 0 && map[i][j - 1] == '0') ||
					(map[i + 1] && map[i + 1][j] == '0') ||
						(i > 0 && map[i - 1][j] == '0'))
					error("Map is not closed", NULL, game);
			}
			j++;
		}
		i++;
	}
}

int	check_args(t_game *game)
{
	int	result;

	result = 0;
	if (game->args != 6)
		result = 1;
	if (access(game->path_north, R_OK) == -1)
		result = 1;
	if (access(game->path_south, R_OK) == -1)
		result = 1;
	if (access(game->path_west, R_OK) == -1)
		result = 1;
	if (access(game->path_east, R_OK) == -1)
		result = 1;
	if (check_ceil_floor(game))
		result = 1;
	free(game->ceiling);
	free(game->floor);
	return (result);
}

int	read_and_check(char *file, t_game *game)
{
	char	**content;
	int		i;

	i = count_lines(file);
	game->rows = i;
	content = fill_content(file, i);
	game->args = 0;
	init_args(game);
	fill_args(content, game);
	if (check_args(game))
		error("Error in arguments", content, game);
	fill_map(content, game);
	free_content(content);
	check_map(game);
	return (0);
}
