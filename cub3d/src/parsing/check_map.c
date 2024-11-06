/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:28:49 by migumar2          #+#    #+#             */
/*   Updated: 2024/09/25 19:20:52 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_walls(char **map)
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
				map[i][j] = '1';
			j++;
		}
		i++;
	}
}

int	has_player(char **map, t_game *game)
{
	int	i;
	int	j;
	int	player;

	i = -1;
	player = 0;
	game->player = malloc(sizeof(t_player));
	while (map[++i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' ||
				map[i][j] == 'W' || map[i][j] == 'E')
			{
				player++;
				game->player->pos_y = i + 0.5;
				game->player->pos_x = j + 0.5;
				set_orientation(map[i][j], game);
				map[i][j] = '0';
			}
			j++;
		}
	}
	return (player);
}

int	check_walls(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[j])
		j++;
	j--;
	while (map[0][i])
	{
		if ((map[0][i] != '1' && map[0][i] != ' ') ||
			(map[j][i] != '1' && map[j][i] != ' '))
			return (1);
		i++;
	}
	i = 0;
	while (map[i] && map[i][0])
	{
		if ((map[i][0] != '1' && map[i][0] != ' ') ||
			(map[i][ft_strlen(map[i]) - 1] != '1'
			&& map[i][ft_strlen(map[i]) - 1] != ' '))
			return (1);
		i++;
	}
	return (0);
}

void	check_map(t_game *game)
{
	if (has_player(game->map, game) != 1)
		error("There is not just one player", NULL, game);
	if (check_walls(game->map))
		error("Map is not surrounded by walls", NULL, game);
	fill_flood(game->map, game);
	fill_walls(game->map);
}
