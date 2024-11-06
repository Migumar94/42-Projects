/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 15:57:34 by migumar2          #+#    #+#             */
/*   Updated: 2024/03/21 23:31:28 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
	{
		move_to_up((t_map *)param);
	}
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
	{
		move_to_left((t_map *)param);
	}
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
	{
		move_to_down((t_map *)param);
	}
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
	{
		move_to_right((t_map *)param);
	}
	if ((keydata.key == MLX_KEY_ESCAPE || keydata.key == MLX_KEY_ENTER)
		&& keydata.action == MLX_RELEASE)
	{
		mlx_close_window(((t_map *)param)->mlx);
	}
}
