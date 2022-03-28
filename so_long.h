/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asherlin <asherlin@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 04:00:00 by asherlin          #+#    #+#             */
/*   Updated: 2022/01/23 22:12:22 by asherlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <unistd.h>
# include <mlx.h>
# include <mlx_int.h>
# include "./libft/libft.h"
# include "get_next_line/get_next_line.h"

# define PIC_SIZE_W 80
# define PIC_SIZE_H 80
# define PLAYER 	"./img/80/t-rex.xpm"
# define COLL 		"./img/80/man2.xpm"
# define EXIT 		"./img/80/gate.xpm"
# define GROUND 	"./img/80/sand.xpm"
# define WALL 		"./img/80/jungle.xpm"

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_move
{
	int	up;
	int	down;
	int	left;
	int	right;
	int	move_count;
}	t_move;

typedef struct s_field
{
	void			*mlx;
	void			*mlx_win;
	t_img			*mlx_img;
	t_img			*player;
	t_img			*exit;
	t_img			*coll;
	t_img			*wall;
	t_img			*ground;
}				t_field;

typedef struct s_data
{
	char	**map;
	int		height;
	int		width;
	t_pos	player;
	t_pos	*colls;
	t_pos	*exits;
	int		exits_count;
	int		colls_count;
	int		collected;
	t_move	moves;
	t_field	*field;
}	t_data;

int				parce_map(char *file, t_data *data);
int				verify_map(t_data *data);
int				find_positions(t_data *data);
t_field			*create_field(t_data *data);
void			show_map(t_data *data);

void			show_map_test(t_data *data);

unsigned int	mlx_get_pixel(t_img *img, int x, int y);
void			mlx_draw_pixel(t_img *mlx_img, int x, int y, int color);
unsigned int	mlx_rgb_to_int(int o, int r, int g, int b);

int				push_the_button(int keycode, t_data *data);
int				release_the_button(int keycode, t_data *data);
int				destroy_hook(t_data *data);

void			refresh_map(t_data *data);

void			move_up(t_data *data, int x, int y);
void			move_down(t_data *data, int x, int y);
void			move_left(t_data *data, int x, int y);
void			move_right(t_data *data, int x, int y);

void			end_game(t_data *data, char *errmessage);
void			errmsg(char *errmessage, int f);
void			field_free(t_field *field, char *errmessage);

#endif 