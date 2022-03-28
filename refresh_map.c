/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asherlin <asherlin@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 04:00:00 by asherlin          #+#    #+#             */
/*   Updated: 2022/03/27 10:34:32 by asherlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	take_a_step(t_data *data, int x, int y);
static void	collect(t_data *data);
static void	exit_check(t_data *data);

void	refresh_map(t_data *data)
{
	int				curr_x;
	int				curr_y;

	curr_x = data->player.x;
	curr_y = data->player.y;
	if (data->moves.up != 0)
		move_up(data, curr_x, curr_y);
	else if (data->moves.down != 0)
		move_down(data, curr_x, curr_y);
	else if (data->moves.left != 0)
		move_left(data, curr_x, curr_y);
	else if (data->moves.right != 0)
		move_right(data, curr_x, curr_y);
	take_a_step(data, curr_x, curr_y);
	collect(data);
	show_map(data);
	exit_check(data);
}

static void	take_a_step(t_data *data, int x, int y)
{
	if (data->player.x != x || data->player.y != y)
	{
		data->moves.move_count++;
		ft_putnbr_fd(data->moves.move_count, 1);
		ft_putendl_fd("", 1);
	}
}

static void	collect(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->colls_count)
	{
		if (data->colls[i].x == data->player.x
			&& data->colls[i].y == data->player.y)
		{
			data->colls[i].x = -1;
			data->colls[i].y = -1;
			data->collected++;
		}
		i++;
	}
}

static void	exit_check(t_data *data)
{
	int	k;

	k = 0;
	while (k < data->exits_count)
	{
		if (data->exits[k].x == data->player.x
			&& data->exits[k].y == data->player.y)
			if (data->colls_count == data->collected)
				end_game(data, NULL);
		k++;
	}
}
