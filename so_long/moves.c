/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 22:01:31 by migumar2          #+#    #+#             */
/*   Updated: 2024/03/21 23:37:40 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	write_moves(t_map *maps)
{
	maps->movs++;
	ft_printf("Moves: %d\n", maps->movs);
}

void	move_to_up(t_map *maps)
{
	if (maps->map[maps->actual_row - 1][maps->actual_column] != '1')
	{
		if (maps->map[maps->actual_row - 1][maps->actual_column] == 'C')
		{
			check_door(maps);
			maps->map[maps->actual_row - 1][maps->actual_column] = '0';
		}
		if (maps->map[maps->actual_row][maps->actual_column] == 'E')
			print_door(maps->mlx, maps->actual_row, maps->actual_column);
		else
			print_floor(maps->mlx, maps->actual_row, maps->actual_column);
		print_player(maps->mlx, maps->actual_row - 1, maps->actual_column);
		maps->actual_row--;
		write_moves(maps);
		if (maps->map[maps->actual_row][maps->actual_column] == 'E'
			&& maps->collects == 0)
			mlx_close_window(maps->mlx);
	}
}

void	move_to_down(t_map *maps)
{
	if (maps->map[maps->actual_row + 1][maps->actual_column] != '1')
	{
		if (maps->map[maps->actual_row + 1][maps->actual_column] == 'C')
		{
			check_door(maps);
			maps->map[maps->actual_row + 1][maps->actual_column] = '0';
		}
		if (maps->map[maps->actual_row][maps->actual_column] == 'E')
			print_door(maps->mlx, maps->actual_row, maps->actual_column);
		else
			print_floor(maps->mlx, maps->actual_row, maps->actual_column);
		print_player(maps->mlx, maps->actual_row + 1, maps->actual_column);
		maps->actual_row++;
		write_moves(maps);
		if (maps->map[maps->actual_row][maps->actual_column] == 'E'
			&& maps->collects == 0)
			mlx_close_window(maps->mlx);
	}
}

void	move_to_right(t_map *maps)
{
	if (maps->map[maps->actual_row][maps->actual_column + 1] != '1')
	{
		if (maps->map[maps->actual_row][maps->actual_column + 1] == 'C')
		{
			check_door(maps);
			maps->map[maps->actual_row][maps->actual_column + 1] = '0';
		}
		if (maps->map[maps->actual_row][maps->actual_column] == 'E')
			print_door(maps->mlx, maps->actual_row, maps->actual_column);
		else
			print_floor(maps->mlx, maps->actual_row, maps->actual_column);
		print_player(maps->mlx, maps->actual_row, maps->actual_column + 1);
		maps->actual_column++;
		write_moves(maps);
		if (maps->map[maps->actual_row][maps->actual_column] == 'E'
			&& maps->collects == 0)
			mlx_close_window(maps->mlx);
	}
}

void	move_to_left(t_map *maps)
{
	if (maps->map[maps->actual_row][maps->actual_column - 1] != '1')
	{
		if (maps->map[maps->actual_row][maps->actual_column - 1] == 'C')
		{
			check_door(maps);
			maps->map[maps->actual_row][maps->actual_column - 1] = '0';
		}
		if (maps->map[maps->actual_row][maps->actual_column] == 'E')
			print_door(maps->mlx, maps->actual_row, maps->actual_column);
		else
			print_floor(maps->mlx, maps->actual_row, maps->actual_column);
		print_player(maps->mlx, maps->actual_row, maps->actual_column - 1);
		maps->actual_column--;
		write_moves(maps);
		if (maps->map[maps->actual_row][maps->actual_column] == 'E'
			&& maps->collects == 0)
			mlx_close_window(maps->mlx);
	}
}
