/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholland <jholland@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 20:20:15 by migumar2          #+#    #+#             */
/*   Updated: 2024/09/24 20:30:38 by jholland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../MLX42/include/MLX42/MLX42.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>

/* define */
# define MAP_WIDTH	1080
# define MAP_HEIGHT	720

# define FOV		60.0
# define D_ANGLE	1.5
# define PL_STEP	0.075
# define M_PI		3.14159265358979323846
# define M_PI_2		1.57079632679489661923

typedef u_int32_t	t_u_int32;
typedef u_int8_t	t_u_int8;

typedef struct s_walls
{
	mlx_image_t		*north_img;
	mlx_image_t		*east_img;
	mlx_image_t		*south_img;
	mlx_image_t		*west_img;
}	t_walls;

typedef struct s_player
{
	double	orientation;
	double	pos_x;
	double	pos_y;
}	t_player;

typedef struct s_ray
{
	double			angle;
	double			cos;
	double			sin;
	double			distance;
	double			x;
	double			y;
	unsigned int	img_column_idx;
	mlx_image_t		*img_collided;
}	t_ray;

typedef struct s_game
{
	int				cancel_paint;
	char			**map;
	int				columns;
	int				rows;
	char			*path_north;
	char			*path_south;
	char			*path_west;
	char			*path_east;
	mlx_image_t		*background;
	char			*floor;
	char			*ceiling;
	unsigned int	floor_color;
	unsigned int	ceiling_color;
	int				args;
	mlx_image_t		*canvas;
	t_player		*player;
	t_walls			walls;
	mlx_t			*mlx;

}	t_game;

/* UTILS */
char		*get_next_line(int fd);
void		*ft_calloc(size_t count, size_t size);
size_t		ft_strlen(const char *str);
char		*ft_strchr(char *str, char c);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strdup(char *s1);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		**ft_split(char const *s, char c);
int			ft_atoi(const char *str);
int			ft_strlen2(const char *str);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
int			ft_strncmp(char *s1, char *s2, size_t n);

/* PARSING FUNCTIONS */

int			read_and_check(char *file, t_game *maps);
void		error(char *message, char **content, t_game *game);
void		fill_flood(char **map, t_game *maps);
void		check_map(t_game *game);
int			check_args(t_game *game);
void		fill_args(char **con, t_game *game);
void		init_args(t_game *game);
char		**fill_content(char *file, int lines);
int			count_lines(char *file);
void		set_orientation(char c, t_game *game);
int			check_ceil_floor(t_game *game);

/* GAME FUNCTIONS */
void		my_keyhook(mlx_key_data_t keydata, void *param);
void		paint_px(mlx_image_t *img, t_u_int32 x, t_u_int32 y,
				t_u_int32 color);
void		send_rays(t_game *map, t_ray rays[MAP_WIDTH]);
void		paint_frame(t_game *map);

void		load_wall_txt(t_game *map);
void		paint_bg(mlx_t *mlx, t_game *map);
void		free_content(char **content);
void		free_game(t_game *game);

#endif