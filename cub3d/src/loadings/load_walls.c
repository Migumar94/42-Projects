/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 18:23:05 by jholland          #+#    #+#             */
/*   Updated: 2024/09/24 18:25:38 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_wall_txt(t_game *game)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(game->path_north);
	if (!texture)
		error("Error loading north texture", NULL, game);
	game->walls.north_img = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png(game->path_east);
	if (!texture)
		error("Error loading east texture", NULL, game);
	game->walls.east_img = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png(game->path_south);
	if (!texture)
		error("Error loading south texture", NULL, game);
	game->walls.south_img = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png(game->path_west);
	if (!texture)
		error("Error loading west texture", NULL, game);
	game->walls.west_img = mlx_texture_to_image(game->mlx, texture);
	mlx_delete_texture(texture);
}
