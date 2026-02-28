/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vmap_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamddah <aamddah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 12:43:02 by aamddah           #+#    #+#             */
/*   Updated: 2025/09/21 12:43:02 by aamddah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	is_valid_elem(char c)
{
	return (c == '0' || c == '1' || is_spawning_orientation(c) 
		|| ft_isspace(c));
}

int	is_valid_position(char **map, int x, int y, int max_lines)
{
	if (y < 0 || y >= max_lines || !map[y])
		return (0);
	if (x < 0 || x >= (int)ft_strlen(map[y]))
		return (0);
	return (1);
}

int	check_border_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && !ft_isspace(line[i]))
			return (1);
		i++;
	}
	return (0);
}

int	count_spawn_points(char **map, int max_lines)
{
	int	count;
	int	y;
	int	x;

	count = 0;
	y = 0;
	while (y < max_lines)
	{
		if (!map[y])
			continue ;
		x = 0;
		while (map[y][x])
		{
			if (is_spawning_orientation(map[y][x]))
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

int	is_map_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '0' && 
			!is_spawning_orientation(line[i]) && 
			!ft_isspace(line[i]))
		{
			return (0);
		}
		i++;
	}
	return (1);
}
