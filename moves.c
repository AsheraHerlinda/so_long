/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asherlin <asherlin@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 04:00:00 by asherlin          #+#    #+#             */
/*   Updated: 2022/03/27 10:34:32 by asherlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_data *data, int x, int y)
{
	if (data->map[y - 1][x] != '1')
		data->player.y -= 1;
}

void	move_down(t_data *data, int x, int y)
{
	if (data->map[y + 1][x] != '1')
		data->player.y += 1;
}

void	move_left(t_data *data, int x, int y)
{
	if (data->map[y][x - 1] != '1')
		data->player.x -= 1;
}

void	move_right(t_data *data, int x, int y)
{
	if (data->map[y][x + 1] != '1')
		data->player.x += 1;
}
