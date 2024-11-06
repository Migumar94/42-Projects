/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholland <jholland@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 13:32:25 by migumar2          #+#    #+#             */
/*   Updated: 2024/09/24 19:57:45 by jholland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_isdigit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	set_orientation(char c, t_game *game)
{
	if (c == 'N')
		game->player->orientation = -M_PI_2;
	else if (c == 'E')
		game->player->orientation = 0;
	else if (c == 'S')
		game->player->orientation = M_PI_2;
	else if (c == 'W')
		game->player->orientation = M_PI;
}

static int	check_floor(t_game *game)
{
	char	**aux;
	char	*ld;
	int		error;
	int		num1;
	int		num2;

	error = 0;
	aux = ft_split(game->floor, ',');
	if (!aux)
		return (1);
	ld = ft_substr(aux[2], 0, ft_strlen(aux[2]));
	if (ld && ft_isdigit(aux[0]) && ft_isdigit(aux[1]) && ft_isdigit(ld))
	{
		num1 = ft_atoi(aux[0]);
		num2 = ft_atoi(aux[1]);
		game->floor_color = num1 << 24 | num2 << 16 | ft_atoi(ld) << 8 | 0xFF;
		if (num1 < 0 || num1 > 255 || num2 < 0
			|| num2 > 255 || ft_atoi(ld) < 0 || ft_atoi(ld) > 255)
			error = 1;
	}
	else
		error = 1;
	free_content(aux);
	free(ld);
	return (error);
}

static int	check_ceil(t_game *game)
{
	char	**aux;
	char	*ld;
	int		error;

	error = 0;
	aux = ft_split(game->ceiling, ',');
	if (!aux)
		return (1);
	ld = ft_substr(aux[2], 0, ft_strlen(aux[2]));
	if (aux[0] && ft_isdigit(aux[0]) && aux[1]
		&& ft_isdigit(aux[1]) && ld && ft_isdigit(ld))
	{
		game->ceiling_color = ft_atoi(aux[0]) << 24
			| ft_atoi(aux[1]) << 16 | ft_atoi(ld) << 8 | 0xFF;
		if (ft_atoi(aux[0]) < 0 || ft_atoi(aux[0]) > 255 || ft_atoi(aux[1]) < 0
			|| ft_atoi(aux[1]) > 255 || ft_atoi(ld) < 0 || ft_atoi(ld) > 255)
			error = 1;
	}
	else
		error = 1;
	free_content(aux);
	free(ld);
	return (error);
}

int	check_ceil_floor(t_game *game)
{
	if (check_floor(game))
		return (1);
	return (check_ceil(game));
}
