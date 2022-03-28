/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asherlin <asherlin@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 04:00:00 by asherlin          #+#    #+#             */
/*   Updated: 2022/03/27 10:34:32 by asherlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_map(t_data *data);
static void	draw_texture(t_field *field, t_img *img, int x, int y);
static void	draw_object(t_data *data, int i, int j);

void	show_map(t_data *data)
{
	draw_map(data);
	mlx_put_image_to_window(data->field->mlx, data->field->mlx_win, \
							data->field->mlx_img, 0, 0);
}

static void	draw_map(t_data *data)
{
	int				i;
	int				j;

	j = 0;
	while (j < data->height)
	{
		i = 0;
		while (i < data->width)
		{
			if (data->map[j][i] == '1')
				draw_texture(data->field, data->field->wall, i * PIC_SIZE_W, \
							j * PIC_SIZE_H);
			else
				draw_texture(data->field, data->field->ground, i * PIC_SIZE_W, \
							j * PIC_SIZE_H);
			draw_object(data, i, j);
			i++;
		}
		j++;
	}
}

static void	draw_texture(t_field *field, t_img *img, int x, int y)
{
	unsigned int	color;
	int				i;
	int				j;

	j = 0;
	while (j < PIC_SIZE_H)
	{
		i = 0;
		while (i < PIC_SIZE_W)
		{
			color = mlx_get_pixel(img, i, j);
			if (color != mlx_rgb_to_int(0, 255, 255, 255))
				mlx_draw_pixel(field->mlx_img, x + i, y + j, color);
			i++;
		}
		j++;
	}
}

static void	draw_object(t_data *data, int i, int j)
{
	int	k;

	k = 0;
	while (k < data->exits_count)
	{
		if (data->exits[k].x == i && data->exits[k].y == j)
			draw_texture(data->field, data->field->exit, \
					i * PIC_SIZE_W, j * PIC_SIZE_H);
		k++;
	}
	k = 0;
	while (k < data->colls_count)
	{
		if (data->colls[k].x == i && data->colls[k].y == j)
			draw_texture(data->field, data->field->coll, \
					i * PIC_SIZE_W, j * PIC_SIZE_H);
		k++;
	}
	if (data->player.x == i && data->player.y == j)
		draw_texture(data->field, data->field->player, \
					i * PIC_SIZE_W, j * PIC_SIZE_H);
}
