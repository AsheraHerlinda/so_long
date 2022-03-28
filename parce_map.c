/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parce_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asherlin <asherlin@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 04:00:00 by asherlin          #+#    #+#             */
/*   Updated: 2022/03/27 10:34:32 by asherlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void		map_height(char *file, t_data *data);
static int	create_map(char *file, t_data *data);

int	parce_map(char *file, t_data *data)
{
	map_height(file, data);
	data->map = malloc (sizeof(char *) * (data->height + 1));
	if (!data->map)
		end_game(data, "data->map malloc error");
	create_map(file, data);
	if (!(verify_map(data)))
		end_game(data, NULL);
	data->colls = (t_pos *) malloc(sizeof(t_pos) * (data->colls_count));
	if (!data->colls)
		end_game(data, "colls malloc error");
	data->exits = (t_pos *) malloc(sizeof(t_pos) * (data->exits_count));
	if (!data->exits)
		end_game(data, "exits malloc error");
	data->exits_count = 0;
	data->colls_count = 0;
	find_positions(data);
	return (1);
}

void	map_height(char *file, t_data *data)
{
	char	*line;
	int		fd;

	data->height = 0;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		data->height++;
		free(line);
		line = (get_next_line(fd));
	}
	free(line);
	close(fd);
}

static int	create_map(char *file, t_data *data)
{
	int	i;
	int	fd;

	fd = open(file, O_RDONLY);
	i = 0;
	while (1)
	{
		data->map[i] = get_next_line(fd);
		if (!data->map[i])
			break ;
		i++;
	}
	if (i == 0)
	{
		close(fd);
		end_game(data, "create map error");
	}
	close(fd);
	return (i);
}
