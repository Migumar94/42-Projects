/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholland <jholland@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:06:31 by migumar2          #+#    #+#             */
/*   Updated: 2024/09/25 14:09:53 by jholland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_ext(char *name)
{
	int	len;

	len = ft_strlen(name);
	if (len >= 4 && name[len - 1] == 'b' && name[len - 2] == 'u'
		&& name[len - 3] == 'c' && name[len - 4] == '.')
		return (1);
	return (0);
}

static void	start_game(t_game *game)
{
	paint_bg(game->mlx, game);
	paint_frame(game);
	mlx_key_hook(game->mlx, my_keyhook, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2 || !check_ext(argv[1]))
		error("Invalid arguments", NULL, NULL);
	read_and_check(argv[1], &game);
	game.mlx = mlx_init(MAP_WIDTH, MAP_HEIGHT, "cub3d", false);
	load_wall_txt(&game);
	start_game(&game);
	free_game(&game);
	return (0);
}
