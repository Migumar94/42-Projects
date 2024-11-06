/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 19:32:59 by migumar2          #+#    #+#             */
/*   Updated: 2024/03/22 00:03:20 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_door(t_map *maps)
{
	int	i;
	int	j;

	i = 0;
	while (maps->map[i])
	{
		j = 0;
		while (maps->map[i][j])
		{
			if (maps->map[i][j] == 'E')
			{
				maps->door_row = i;
				maps->door_column = j;
			}
			j++;
		}
		i++;
	}
}

void	check_door(t_map *maps)
{
	maps->collects--;
	if (maps->collects == 0)
	{
		print_steps(maps->mlx, maps->door_row, maps->door_column);
	}
}

void	print_steps(mlx_t *mlx, int i, int j)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png("./assets/steps.png");
	if (!texture)
		error();
	img = mlx_texture_to_image(mlx, texture);
	mlx_delete_texture(texture);
	if (!img)
		error();
	if (mlx_image_to_window(mlx, img, j * IMG_WIDTH, i * IMG_HEIGHT) < 0)
		error();
}
