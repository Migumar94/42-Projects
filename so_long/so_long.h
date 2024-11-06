/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:25:17 by migumar2          #+#    #+#             */
/*   Updated: 2024/03/20 18:33:49 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42/include/MLX42/MLX42.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdint.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <stdio.h>
# include <stdarg.h>

/* define */
# define MAP_WIDTH	7100
# define MAP_HEIGHT	7100
# define IMG_WIDTH	71
# define IMG_HEIGHT	71

typedef struct s_map
{
	char	**map;
	int		columns;
	int		rows;
	int		collects;
	int		actual_row;
	int		actual_column;
	int		door_row;
	int		door_column;
	int		movs;
	mlx_t	*mlx;

}			t_map;

char	*get_next_line(int fd);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *str);
char	*ft_strchr(char *str, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_joinandfree(char *storage, char *buffer);
void	error(void);
char	**read_and_check(char *file, t_map	*maps);
int		is_rectangle(char **map);
int		have_wall(char **map, int lines, int len);
int		have_exit_and_spawn(char **map);
int		have_coins(char **map);
int		have_wrong_char(char **map);
int		fill_flood(char **map);
char	**copy_map(char **map, int lines);
void	free_map(char **map);
int		check_ext(char *name);
int		start_game(t_map *maps);
void	my_keyhook(mlx_key_data_t keydata, void *param);
void	put_spawn(t_map *maps);
void	move_to_up(t_map *maps);
void	print_floor(mlx_t *mlx, int i, int j);
void	print_wall(mlx_t *mlx, int i, int j);
void	print_coin(mlx_t *mlx, int i, int j);
void	print_player(mlx_t *mlx, int i, int j);
void	print_door(mlx_t *mlx, int i, int j);
void	print_steps(mlx_t *mlx, int i, int j);
void	move_to_down(t_map *maps);
void	move_to_right(t_map *maps);
void	move_to_left(t_map *maps);
void	put_door(t_map *maps);
void	check_door(t_map *maps);
void	count_coins(t_map *maps);
int		ft_printf(char const *str, ...);
void	ft_print_c(char c, int *total);
#endif