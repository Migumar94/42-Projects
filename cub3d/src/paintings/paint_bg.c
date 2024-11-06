/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint_bg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholland <jholland@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 20:51:28 by jholland          #+#    #+#             */
/*   Updated: 2024/09/24 20:03:32 by jholland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// A segmentation fault protected 'mlx_put_pixel'
void	paint_px(mlx_image_t *img, t_u_int32 x, t_u_int32 y, t_u_int32 color)
{
	if (x < img->width && y < img->height)
		mlx_put_pixel(img, x, y, color);
}

void	paint_bg(mlx_t *mlx, t_game *game)
{
	t_u_int32	x;
	t_u_int32	y;
	t_u_int32	y2;

	y2 = MAP_HEIGHT / 2;
	game->background = mlx_new_image(mlx, MAP_WIDTH, MAP_HEIGHT);
	y = 0;
	while (y < y2)
	{
		x = 0;
		while (x < MAP_WIDTH)
		{
			paint_px(game->background, x, y, game->ceiling_color);
			paint_px(game->background, x, y + y2, game->floor_color);
			x++;
		}
		y++;
	}
	mlx_image_to_window(mlx, game->background, 0, 0);
}
