/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asherlin <asherlin@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 04:00:00 by asherlin          #+#    #+#             */
/*   Updated: 2022/03/27 10:34:32 by asherlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_data	*create_data(void);
static int		check_extension(char *file);

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
		errmsg("incorrect nums of arguments", 1);
	if (!check_extension(argv[1]))
		errmsg("incorrect type of argument", 1);
	data = create_data();
	parce_map(argv[1], data);
	data->field = create_field(data);
	show_map(data);
	mlx_hook(data->field->mlx_win, 2, 1L << 0, push_the_button, data);
	mlx_hook(data->field->mlx_win, 3, 1L << 1, release_the_button, data);
	mlx_hook(data->field->mlx_win, 17, 1L << 17, destroy_hook, data);
	mlx_loop(data->field->mlx);
	return (0);
}

static int	check_extension(char *file)
{
	int				len;

	len = ft_strlen(file);
	if (file == NULL)
		return (0);
	if (len < 5)
		return (0);
	if (ft_strncmp(file + (len - 4), ".ber", 4))
		return (0);
	return (1);
}

static t_data	*create_data(void)
{
	t_data	*data;

	data = (t_data *) malloc (sizeof(t_data));
	if (!data)
		errmsg ("data malloc error", 1);
	data->map = 0;
	data->height = 0;
	data->width = 0;
	data->player.x = 0;
	data->player.y = 0;
	data->colls = 0;
	data->exits = 0;
	data->exits_count = 0;
	data->colls_count = 0;
	data->collected = 0;
	data->moves.move_count = 0;
	data->moves.down = 0;
	data->moves.up = 0;
	data->moves.left = 0;
	data->moves.right = 0;
	data->field = 0;
	return (data);
}
