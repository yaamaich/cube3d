/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamddah <aamddah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 11:51:56 by aamddah           #+#    #+#             */
/*   Updated: 2025/09/21 11:51:56 by aamddah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"
#include <string.h>

int	check_sides(char **map, char current, int x, int y)
{
	if (x == 0 || map[y][x + 1] == '\0')
	{
		if (current != '1' && !ft_isspace(current))
		{
			ft_putstr_fd("Error\n Map sides\n", 2);
			return (1);
		}
	}
	return (0);
}

int	check_around(char **map, int x, int y, int max_lines)
{
	int		i;
	int		new_x;
	int		new_y;
	char	p2;
	int		directions[4][2];

	init_array(directions);
	i = 0;
	while (i < 4)
	{
		new_x = x + directions[i][0];
		new_y = y + directions[i][1];
		if (!is_valid_position(map, new_x, new_y, max_lines))
			return (1);
		p2 = map[new_y][new_x];
		if (!is_valid_elem(p2) || ft_isspace(p2))
			return (1);
		i++;
	}
	return (0);
}

int	the_check(char **map, int x, int y, int max_lines)
{
	char	current;

	while (y < max_lines)
	{
		if (!map[y])
			continue ;
		x = 0;
		while (map[y][x])
		{
			current = map[y][x];
			if (!is_valid_elem(current))
				return (ft_putstr_fd("Error\n Invalid element\n", 2), 1);
			if (current == '0' || is_spawning_orientation(current))
			{
				if (check_around(map, x, y, max_lines))
					return (ft_putstr_fd("Error\n Check around \
walkable\n", 2), 1);
			}
			if (check_sides(map, current, x, y))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

int	validate_map(char **map, int max_lines)
{
	int	y;
	int	x;

	if (max_lines < 3)
	{
		ft_putstr_fd("Error\n Map must have at least 3 lines\n", 2);
		return (1);
	}
	if (check_border_line(map[0]) || check_border_line(map[max_lines - 1]))
		return (ft_putstr_fd("Error\n Map borders\n", 2), 1);
	if (count_spawn_points(map, max_lines) != 1)
	{
		ft_putstr_fd("Error\n number of spawn point\n", 2);
		return (1);
	}
	y = 0;
	x = 0;
	return (the_check(map, x, y, max_lines));
}

char	*get_trimmed(char *line, char **trimmed)
{
	int	i;

	ft_free(trimmed);
	if (!line)
		return (NULL);
	*trimmed = ft_strtrim(line, "\n");
	i = 0;
	while (*trimmed && (*trimmed)[i])
	{
		if ((*trimmed)[i] == '\n' || (*trimmed)[i] == '\r')
			(*trimmed)[i] = '\0';
		i++;
	}
	return (*trimmed);
}
