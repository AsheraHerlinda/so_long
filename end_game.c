/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asherlin <asherlin@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 04:00:00 by asherlin          #+#    #+#             */
/*   Updated: 2022/03/27 10:34:32 by asherlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	data_free(t_data *data, char *errmessage);

void	end_game(t_data *data, char *errmessage)
{
	if (errmessage)
		errmsg(errmessage, 0);
	if (data != 0)
		data_free(data, NULL);
	exit (1);
}

static void	data_free(t_data *data, char *errmessage)
{
	int	i;

	if (errmessage)
		errmsg(errmessage, 0);
	if (data != 0)
	{
		if (data->colls != 0)
			free(data->colls);
		if (data->exits != 0)
			free(data->exits);
		if (data->map != 0)
		{
			i = 0;
			while (data->height > i)
			{
				free(data->map[i]);
				i++;
			}
			free(data->map);
		}
	}
	if (data->field != 0)
		field_free(data->field, NULL);
	free(data);
}

void	field_free(t_field *field, char *errmessage)
{
	if (field != 0)
	{
		if (field->ground != 0)
			mlx_destroy_image(field->mlx, field->ground);
		if (field->wall != 0)
			mlx_destroy_image(field->mlx, field->wall);
		if (field->coll != 0)
			mlx_destroy_image(field->mlx, field->coll);
		if (field->exit != 0)
			mlx_destroy_image(field->mlx, field->exit);
		if (field->player != 0)
			mlx_destroy_image(field->mlx, field->player);
		if (field->mlx_img != 0)
			mlx_destroy_image(field->mlx, field->mlx_img);
		if (field->mlx_win != 0)
			mlx_destroy_window(field->mlx, field->mlx_win);
		if (field->mlx != 0)
			mlx_destroy_display(field->mlx);
		free(field->mlx);
		free(field);
	}
	if (errmessage)
		errmsg(errmessage, 0);
}

void	errmsg(char *errmessage, int f)
{
	ft_putendl_fd(errmessage, 1);
	if (f == 1)
		exit (1);
}
