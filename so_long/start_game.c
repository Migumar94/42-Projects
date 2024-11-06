/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:43:43 by migumar2          #+#    #+#             */
/*   Updated: 2024/03/21 23:38:36 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	add_the_texture(mlx_t *mlx, char c, int i, int j)
{
	if (c == 'P')
	{
		print_floor(mlx, i, j);
		print_player(mlx, i, j);
	}
	if (c == 'C')
	{
		print_floor(mlx, i, j);
		print_coin(mlx, i, j);
	}
	if (c == '1')
		print_wall(mlx, i, j);
	if (c == '0')
		print_floor(mlx, i, j);
	if (c == 'E')
		print_door(mlx, i, j);
}

void	add_textures(mlx_t *mlx, t_map *t_map)
{
	int				i;
	int				j;

	i = 0;
	while (i < t_map->rows)
	{
		j = 0;
		while (j < t_map->columns)
		{
			add_the_texture(mlx, t_map->map[i][j], i, j);
			j++;
		}
		i++;
	}
}

int	start_game(t_map *maps)
{
	if (!maps)
		error();
	maps->mlx = mlx_init(maps->columns * IMG_WIDTH,
			maps->rows * IMG_HEIGHT, "SO_LONG", false);
	if (!maps->mlx)
		error();
	put_spawn(maps);
	put_door(maps);
	maps->collects = 0;
	maps->movs = 0;
	count_coins(maps);
	add_textures (maps->mlx, maps);
	mlx_key_hook(maps->mlx, &my_keyhook, maps);
	mlx_loop(maps->mlx);
	printf("mxl: %p\n", maps->mlx);
	mlx_terminate(maps->mlx);
	return (EXIT_SUCCESS);
}
