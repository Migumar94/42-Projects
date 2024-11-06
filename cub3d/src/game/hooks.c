/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholland <jholland@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:57:34 by migumar2          #+#    #+#             */
/*   Updated: 2024/09/24 19:57:34 by jholland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	turn_hooks(mlx_t *mlx, t_player *player)
{
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
		player->orientation = player->orientation - D_ANGLE / 180 * M_PI;
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
		player->orientation = player->orientation + D_ANGLE / 180 * M_PI;
}

static double	mv_vect(mlx_t *mlx, t_player *pl, double *mv_x, double *mv_y)
{
	if (mlx_is_key_down(mlx, MLX_KEY_W))
	{
		*mv_x += cos(pl->orientation);
		*mv_y += sin(pl->orientation);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_S))
	{
		*mv_x -= cos(pl->orientation);
		*mv_y -= sin(pl->orientation);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_A))
	{
		*mv_x += sin(pl->orientation);
		*mv_y -= cos(pl->orientation);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_D))
	{
		*mv_x -= sin(pl->orientation);
		*mv_y += cos(pl->orientation);
	}
	if (*mv_x == 0 && *mv_y == 0)
		return (0);
	return (sqrt(pow(*mv_x, 2) + pow(*mv_y, 2)));
}

static void	move_hooks(char **map, mlx_t *mlx, t_player *player)
{
	double	mv_x;
	double	mv_y;
	double	mv;

	mv_x = 0;
	mv_y = 0;
	mv = mv_vect(mlx, player, &mv_x, &mv_y);
	if (!mv)
		return ;
	mv_x = mv_x * PL_STEP / mv;
	mv_y = mv_y * PL_STEP / mv;
	if (map[(int)(player->pos_y + 5 * mv_y)][(int)player->pos_x] == '1')
		return ;
	if (map[(int)(player->pos_y)][(int)(player->pos_x + 5 * mv_x)] == '1')
		return ;
	if (map[(int)(player->pos_y + 5 * mv_y)][(int)(player->pos_x + 5 * mv_x)]
		== '1')
		return ;
	player->pos_x = player->pos_x + mv_x;
	player->pos_y = player->pos_y + mv_y;
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	turn_hooks(game->mlx, game->player);
	move_hooks(game->map, game->mlx, game->player);
	if (mlx_is_key_down(game->mlx, MLX_KEY_W)
		|| mlx_is_key_down(game->mlx, MLX_KEY_A)
		|| mlx_is_key_down(game->mlx, MLX_KEY_S)
		|| mlx_is_key_down(game->mlx, MLX_KEY_D)
		|| mlx_is_key_down(game->mlx, MLX_KEY_LEFT)
		|| mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
		paint_frame(game);
	if ((keydata.key == MLX_KEY_ESCAPE || keydata.key == MLX_KEY_ENTER)
		&& keydata.action == MLX_PRESS)
		mlx_close_window(((t_game *)param)->mlx);
}
