/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_positions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asherlin <asherlin@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 04:00:00 by asherlin          #+#    #+#             */
/*   Updated: 2022/03/27 10:34:32 by asherlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	fill_colls_positions(t_data *data, int x, int y);
static int	fill_exit_position(t_data *data, int x, int y);

int	find_positions(t_data *data)
{
	int		x;
	int		y;

	x = 1;
	y = 1;
	while (y < data->height)
	{
		while (data->map[y][x] != '\n' && data->map[y][x] != '\0')
		{
			if (data->map[y][x] == 'P')
			{
				data->player.x = x;
				data->player.y = y;
			}
			if (data->map[y][x] == 'C')
				fill_colls_positions(data, x, y);
			if (data->map[y][x] == 'E')
				fill_exit_position(data, x, y);
			x++;
		}
		x = 1;
		y++;
	}
	return (0);
}

static int	fill_colls_positions(t_data *data, int x, int y)
{
	data->colls[data->colls_count].x = x;
	data->colls[data->colls_count].y = y;
	data->colls_count += 1;
	return (1);
}

static int	fill_exit_position(t_data *data, int x, int y)
{
	data->exits[data->exits_count].x = x;
	data->exits[data->exits_count].y = y;
	data->exits_count += 1;
	return (1);
}
