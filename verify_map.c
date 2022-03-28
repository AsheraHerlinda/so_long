/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asherlin <asherlin@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1970/01/01 04:00:00 by asherlin          #+#    #+#             */
/*   Updated: 2022/03/27 10:34:32 by asherlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_verify_extreme_lines(t_data *data, char *line);
static int	ft_verify_lines(t_data *data, int h, int w);
static int	check_borders(char *line, int w);
static int	check_symbols(char *line, int *flags);

int	verify_map(t_data *data)
{
	if (data->height <= 2)
	{
		errmsg("too low height of the map", 0);
		return (0);
	}
	if (!ft_verify_extreme_lines(data, data->map[0]))
		return (0);
	if (!ft_verify_lines(data, data->height, data->width))
		return (0);
	if (data->width != (ft_verify_extreme_lines(data, \
		data->map[data->height - 1])))
	{
		errmsg("The map is not valid. Incorrect line!", 0);
		return (0);
	}
	return (data->width);
}

static int	ft_verify_extreme_lines(t_data *data, char *line)
{
	int	width;

	width = 0;
	while (line[width] != '\0' && line[width] != '\n')
	{
		if (line[width] != '1')
		{
			errmsg("The map is not valid. Borders are not closed!", 0);
			return (0);
		}
		width++;
	}
	data->width = width;
	if (data->width < 3 && data->height < 5)
	{
		errmsg("too low width of the map", 0);
		return (0);
	}
	return (data->width);
}

static int	ft_verify_lines(t_data *data, int h, int w)
{
	int	flags[3];

	flags[0] = 0;
	flags[1] = 0;
	flags[2] = 0;
	while (h-- > 2)
	{
		if (!check_borders(data->map[h - 1], w))
			return (0);
		if (!check_symbols(data->map[h - 1], flags))
			return (0);
	}
	if (flags[0] != 1 || flags[1] < 1 || flags[2] < 1)
	{
		if (flags[0] != 1)
			errmsg("Incorrect number of players!", 0);
		if (flags[1] < 1)
			errmsg("Too few EXITs!", 0);
		if (flags[2] < 1)
			errmsg("Too few collections!", 0);
		return (0);
	}
	data->exits_count = flags[1];
	data->colls_count = flags[2];
	return (check_borders(data->map[h], w));
}

static int	check_borders(char *line, int w)
{
	int	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (i != w)
	{
		errmsg("The map is not valid. Incorrect line!", 0);
		return (0);
	}
	if (line[0] != '1' || line[w - 1] != '1')
	{
		errmsg("The map is not valid. Borders are not closed!", 0);
		return (0);
	}
	return (i);
}

static int	check_symbols(char *line, int *flags)
{
	int	el;

	el = 0;
	while (line[el] != '\0' && line[el] != '\n')
	{
		if (line[el] != '0' && line[el] != '1' && line[el] != 'P' && \
			line[el] != 'E' && line[el] != 'C')
		{
			errmsg("The map is not valid. Forbidden symbols!", 0);
			return (0);
		}
		else if (line[el] == 'P')
			flags[0] += 1;
		else if (line[el] == 'E')
			flags[1] += 1;
		else if (line[el] == 'C')
			flags[2] += 1;
		el++;
	}
	return (el);
}
