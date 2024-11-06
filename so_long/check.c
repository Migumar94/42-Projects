/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 20:12:02 by migumar2          #+#    #+#             */
/*   Updated: 2024/03/11 18:32:39 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen2(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

int	is_rectangle(char **map)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen2(map[i++]);
	while (map[i])
	{
		if (ft_strlen2(map[i]) != len)
			return (0);
		i++;
	}
	return (len);
}

int	have_coins(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	have_exit_and_spawn(char **map)
{
	int	i;
	int	j;
	int	exit;
	int	spawn;

	exit = 0;
	spawn = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'E')
				exit++;
			if (map[i][j] == 'P')
				spawn++;
			j++;
		}
		i++;
	}
	if (spawn == 1 && exit == 1)
		return (1);
	return (0);
}

int	have_wall(char **map, int lines, int len)
{
	int	i;

	i = 0;
	while (map[0][i] != '\n' && map[0][i] != 0)
	{
		if (map[0][i] != '1' || map[lines - 1][i] != '1')
		{
			return (0);
		}
		i++;
	}
	i = 0;
	while (i < lines)
	{
		if (map[i][0] != '1' || map [i][len - 1] != '1')
		{
			return (0);
		}
		i++;
	}
	return (1);
}
