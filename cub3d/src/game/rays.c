/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholland <jholland@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 17:58:59 by jholland          #+#    #+#             */
/*   Updated: 2024/09/24 19:57:40 by jholland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	grid_points(t_ray *ray, double *d_x, double *d_y, double *grid_angle)
{
	if (ray->cos > 0)
		*d_x = (int)ray->x + 1 - ray->x;
	else if (ray->x == (int)ray->x)
		*d_x = -1;
	else
		*d_x = (int)ray->x - ray->x;
	if (ray->sin > 0)
		*d_y = (int)ray->y + 1 - ray->y;
	else if (ray->y == (int)ray->y)
		*d_y = -1;
	else
		*d_y = (int)ray->y - ray->y;
	*grid_angle = atan(*d_y / *d_x);
	if (*d_x < 0)
		*grid_angle += M_PI;
}

int	collision(t_game *game, t_ray *ray, double grid_angle)
{
	double		fract;

	if (game->map[(int)(ray->y + sin(ray->angle) / 100000)]
		[(int)(ray->x + ray->cos / 100000)] != '1')
		return (0);
	fract = ray->y - (int)ray->y;
	if (ray->cos > 0 && ray->cos > cos(grid_angle))
		ray->img_collided = game->walls.east_img;
	else if (ray->cos < 0 && ray->cos < cos(grid_angle))
		ray->img_collided = game->walls.west_img;
	else
		fract = ray->x - (int)ray->x;
	if (ray->sin > 0 && ray->sin > sin(grid_angle))
		ray->img_collided = game->walls.south_img;
	else if (ray->sin < 0 && ray->sin < sin(grid_angle))
		ray->img_collided = game->walls.north_img;
	ray->img_column_idx = fract * ray->img_collided->width;
	if (ray->img_collided == game->walls.south_img
		|| ray->img_collided == game->walls.west_img)
		ray->img_column_idx = ray->img_collided->width - ray->img_column_idx;
	return (1);
}

int	ray_step2(t_game *game, t_ray *ray)
{
	double	d_x;
	double	d_y;
	double	grid_angle;

	grid_points(ray, &d_x, &d_y, &grid_angle);
	if (fabs(ray->cos) > fabs(cos(grid_angle)))
	{
		ray->x += d_x;
		ray->y += d_x * tan(ray->angle);
	}
	else
	{
		ray->y += d_y;
		ray->x += d_y / tan(ray->angle);
	}
	if (collision(game, ray, grid_angle))
		return (0);
	return (1);
}

void	calculate_distance(t_game *game, t_ray *ray)
{
	double	x0;
	double	y0;

	x0 = game->player->pos_x;
	y0 = game->player->pos_y;
	ray->x = x0;
	ray->y = y0;
	ray->distance = 0;
	while (ray_step2(game, ray))
		;
	ray->distance = sqrt(pow(ray->x - x0, 2) + pow(ray->y - y0, 2));
	ray->distance *= cos(ray->angle - game->player->orientation);
}

void	send_rays(t_game *game, t_ray rays[MAP_WIDTH])
{
	double	angle;
	int		i;
	double	fov_r;

	fov_r = FOV / 180 * M_PI_2;
	angle = game->player->orientation - fov_r / 2;
	i = 0;
	while (i < MAP_WIDTH)
	{
		rays[i].angle = angle;
		rays[i].cos = cos(angle);
		rays[i].sin = sin(angle);
		calculate_distance(game, &rays[i]);
		angle += fov_r / (MAP_WIDTH - 1);
		i++;
	}
}
