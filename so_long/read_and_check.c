/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_and_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:22:05 by migumar2          #+#    #+#             */
/*   Updated: 2024/03/20 16:35:19 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_lines(char *file)
{
	int		i;
	int		fd;
	char	*aux;
	int		is_line;
	char	*free_line;

	is_line = 1;
	aux = ".";
	i = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error();
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
	if (i < 3)
		error();
	return (i);
}

char	**fill_map(char *file, int lines)
{
	char	**map;
	int		fd;
	int		line;

	line = 0;
	map = ft_calloc((lines + 1), sizeof (char *));
	fd = open(file, O_RDONLY);
	if (fd < 0)
		error();
	map[line] = get_next_line(fd);
	if (!map[line++])
		error();
	while (line < lines)
	{
		map[line] = NULL;
		map[line] = get_next_line(fd);
		if (!map[line])
			error();
		line++;
	}
	close(fd);
	return (map);
}

char	**read_and_check(char *file, t_map	*maps)
{
	char	**map;

	maps->rows = count_lines(file);
	map = fill_map(file, maps->rows);
	maps->columns = is_rectangle(map);
	if (maps->columns >= 3 && maps->rows >= 3
		&& have_wall(map, maps->rows, maps->columns) && have_coins(map)
		&& have_exit_and_spawn(map) && !have_wrong_char(map)
		&& fill_flood(copy_map(map, maps->rows)))
	{
		return (map);
	}
	else
	{
		free_map(map);
		error();
	}
	return (map);
}
