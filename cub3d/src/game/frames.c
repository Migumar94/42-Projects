/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frames.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholland <jholland@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 13:43:43 by migumar2          #+#    #+#             */
/*   Updated: 2024/09/24 20:03:53 by jholland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static unsigned int	get_color(t_u_int8 *array)
{
	unsigned int	color;

	color = array[0] << 24 | array[1] << 16 | array[2] << 8 | array[3];
	return (color);
}

static int	img_color(mlx_image_t *img, t_u_int32 x, t_u_int32 y)
{
	if (!img || x >= img->width || y >= img->height)
		return (0x000000FF);
	return (get_color(&img->pixels[(y * img->width + x) * 4]));
}

static void	paint_line(mlx_image_t *canvas, t_u_int32 x, t_ray *ray)
{
	int			y0;
	t_u_int32	dy;
	t_u_int32	height;
	t_u_int32	color;
	mlx_image_t	*img;

	if (!ray->distance)
		return ;
	height = MAP_WIDTH / ray->distance;
	img = ray->img_collided;
	y0 = MAP_HEIGHT / 2 - height / 2;
	dy = -1;
	if (height > MAP_HEIGHT)
		dy = -y0 - 1;
	while (++dy < height)
	{
		if (y0 + dy > MAP_HEIGHT)
			break ;
		if (!img)
			color = 0x000000FF;
		else
			color = img_color(img, ray->img_column_idx,
					dy * img->height / height);
		paint_px(canvas, x, y0 + dy, color);
	}
}

static void	paint_walls(mlx_image_t *canvas, t_ray rays[MAP_WIDTH])
{
	t_u_int32	x;

	x = 0;
	while (x < MAP_WIDTH)
	{
		paint_line(canvas, x, &rays[x]);
		x++;
	}
}

void	paint_frame(t_game *game)
{
	t_ray		rays[MAP_WIDTH];
	t_u_int32	x;
	t_u_int32	y;

	if (!game->canvas)
	{
		game->canvas = mlx_new_image(game->mlx, MAP_WIDTH, MAP_HEIGHT);
		mlx_image_to_window(game->mlx, game->canvas, 0, 0);
	}
	y = 0;
	while (y < game->canvas->height)
	{
		x = 0;
		while (x < game->canvas->width)
			game->canvas->pixels[(y * game->canvas->width + x++) * 4 + 3] = 0;
		y++;
	}
	send_rays(game, rays);
	paint_walls(game->canvas, rays);
}
