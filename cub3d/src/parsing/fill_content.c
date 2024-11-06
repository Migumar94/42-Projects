/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_content.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholland <jholland@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:26:31 by migumar2          #+#    #+#             */
/*   Updated: 2024/09/24 19:47:08 by jholland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	count_lines(char *file)
{
	int		i;
	int		fd;
	char	*aux;
	char	*free_line;

	aux = ".";
	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error("Error in file opening", NULL, NULL);
	aux = get_next_line(fd);
	while (aux)
	{
		free_line = aux;
		aux = get_next_line(fd);
		free(free_line);
		i++;
	}
	free(aux);
	close(fd);
	return (i);
}

char	**fill_content(char *file, int lines)
{
	char	**map;
	int		fd;
	int		line;

	line = 0;
	map = ft_calloc((lines + 1), sizeof (char *));
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error("Error in file opening", map, NULL);
	map[line] = get_next_line(fd);
	if (!map[line++])
		error("Error in memory allocation", map, NULL);
	while (line < lines)
	{
		map[line] = NULL;
		map[line] = get_next_line(fd);
		if (!map[line])
			error("Error in memory allocation", map, NULL);
		line++;
	}
	close(fd);
	return (map);
}

void	init_args(t_game *game)
{
	game->path_north = NULL;
	game->path_south = NULL;
	game->path_west = NULL;
	game->path_east = NULL;
	game->floor = NULL;
	game->ceiling = NULL;
	game->args = 0;
	game->canvas = NULL;
	game->cancel_paint = 0;
	game->player = NULL;
	game->map = NULL;
}

static int	check_line(char *line)
{
	if (line[0] == '\n')
		return (1);
	if (ft_strlen(line) < 2)
		return (0);
	else if (!ft_strncmp(line, "F ", 2))
		return (1);
	else if (!ft_strncmp(line, "C ", 2))
		return (1);
	else if (ft_strlen(line) < 3)
		return (0);
	else if (!ft_strncmp(line, "NO ", 3))
		return (1);
	else if (!ft_strncmp(line, "SO ", 3))
		return (1);
	else if (!ft_strncmp(line, "WE ", 3))
		return (1);
	else if (!ft_strncmp(line, "EA ", 3))
		return (1);
	return (0);
}

void	fill_args(char **con, t_game *game)
{
	int	i;

	i = 0;
	while (con[i] && game->args != 6)
	{
		if (check_line(con[i]))
		{
			if (!ft_strncmp(con[i], "NO ", 3))
				game->path_north = ft_substr(con[i], 3, ft_strlen(con[i]) - 4);
			else if (!ft_strncmp(con[i], "SO ", 3))
				game->path_south = ft_substr(con[i], 3, ft_strlen(con[i]) - 4);
			else if (!ft_strncmp(con[i], "WE ", 3))
				game->path_west = ft_substr(con[i], 3, ft_strlen(con[i]) - 4);
			else if (!ft_strncmp(con[i], "EA ", 3))
				game->path_east = ft_substr(con[i], 3, ft_strlen(con[i]) - 4);
			else if (!ft_strncmp(con[i], "F ", 2))
				game->floor = ft_substr(con[i], 2, ft_strlen(con[i]) - 3);
			else if (!ft_strncmp(con[i], "C ", 2))
				game->ceiling = ft_substr(con[i], 2, ft_strlen(con[i]) - 3);
			else if (con[i][0] == '\n')
				game->args--;
			game->args++;
		}
		i++;
	}
}
