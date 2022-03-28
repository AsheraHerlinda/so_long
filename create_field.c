/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_field.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asherlin <asherlin@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 04:00:00 by asherlin          #+#    #+#             */
/*   Updated: 2022/03/27 10:34:32 by asherlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

static void	window_init(t_field *field, t_data *data);
static void	texture_init(t_field *field, t_data *data);
static void	texture_load(t_field *field, t_img **img, char *path, t_data *data);

t_field	*create_field(t_data *data)
{
	t_field	*field;

	field = (t_field *)malloc(sizeof(t_field));
	if (field == 0)
		end_game(data, "field malloc error");
	field->mlx = 0;
	field->mlx_win = 0;
	field->mlx_img = 0;
	field->player = 0;
	field->exit = 0;
	field->coll = 0;
	field->wall = 0;
	field->ground = 0;
	window_init(field, data);
	texture_init(field, data);
	return (field);
}

static void	window_init(t_field *field, t_data *data)
{
	field->mlx = mlx_init();
	if (field->mlx == 0)
		end_game(data, "mlx_init error");
	field->mlx_win = mlx_new_window(field->mlx, data->width * PIC_SIZE_W,
			data->height * PIC_SIZE_H, "JURASSIC PARK");
	if (field->mlx_win == 0)
		end_game(data, "mlx_new_window error");
	field->mlx_img = mlx_new_image(field->mlx, data->width * PIC_SIZE_W,
			data->height * PIC_SIZE_H);
	if (field->mlx_img == 0)
		end_game(data, "mlx_new_image error");
}

static void	texture_init(t_field *field, t_data *data)
{
	texture_load(field, &field->player, PLAYER, data);
	texture_load(field, &field->exit, EXIT, data);
	texture_load(field, &field->coll, COLL, data);
	texture_load(field, &field->wall, WALL, data);
	texture_load(field, &field->ground, GROUND, data);
}

static void	texture_load(t_field *field, t_img **img, char *path, t_data *data)
{
	int				width;
	int				height;

	*img = mlx_xpm_file_to_image(field->mlx, path, &width, &height);
	if (*img == 0)
	{
		field_free(field, "texture load error");
		end_game(data, NULL);
	}
	(*img)->width = width;
	(*img)->height = height;
}
