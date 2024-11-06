/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:02:24 by migumar2          #+#    #+#             */
/*   Updated: 2024/03/14 20:15:08 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	have_wrong_char(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != 'E' && map[i][j] != 'P' && map[i][j] != 'C'
				&& map[i][j] != '1' && map[i][j] != '0' && map[i][j] != '\n')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	find_spawn(char **map, int *line, int *pos)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				*line = i;
				*pos = j;
			}
			j++;
		}
		i++;
	}
}

void	fill(char **map, int line, int pos)
{
	if (map[line - 1][pos] != '1')
	{
		map[line - 1][pos] = '1';
		fill(map, line - 1, pos);
	}
	if (map[line][pos + 1] != '1')
	{
		map[line][pos + 1] = '1';
		fill(map, line, pos + 1);
	}
	if (map[line][pos - 1] != '1')
	{
		map[line][pos - 1] = '1';
		fill(map, line, pos - 1);
	}
	if (map[line + 1][pos] != '1')
	{
		map[line + 1][pos] = '1';
		fill(map, line + 1, pos);
	}
}

int	have_exit(char **map)
{
	int	i;
	int	j;
	int	exit;

	exit = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				exit++;
			j++;
		}
		i++;
	}
	if (exit == 1)
		return (1);
	return (0);
}

int	fill_flood(char **map)
{
	int	line;
	int	pos;

	find_spawn(map, &line, &pos);
	map[line][pos] = '1';
	fill(map, line, pos);
	if (!have_exit(map) && !have_coins(map))
	{
		free_map(map);
		return (1);
	}
	free_map(map);
	return (0);
}
