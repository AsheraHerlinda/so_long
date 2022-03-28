/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asherlin <asherlin@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 04:00:00 by asherlin          #+#    #+#             */
/*   Updated: 2022/03/27 10:34:32 by asherlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	push_the_button(int keycode, t_data *data)
{
	if (keycode == 65307)
		end_game(data, NULL);
	if (keycode == 119)
		data->moves.up = 1;
	if (keycode == 115)
		data->moves.down = 1;
	if (keycode == 97)
		data->moves.left = 1;
	if (keycode == 100)
		data->moves.right = 1;
	refresh_map(data);
	return (0);
}

int	release_the_button(int keycode, t_data *data)
{
	if (keycode == 119)
		data->moves.up = 0;
	if (keycode == 115)
		data->moves.down = 0;
	if (keycode == 97)
		data->moves.left = 0;
	if (keycode == 100)
		data->moves.right = 0;
	refresh_map(data);
	return (0);
}

int	destroy_hook(t_data *data)
{
	(void)data;
	end_game(data, NULL);
	return (0);
}
