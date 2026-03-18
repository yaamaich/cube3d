/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 20:37:21 by yaamaich          #+#    #+#             */
/*   Updated: 2026/03/18 20:39:20 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_dirs(int *dir_y, int *dir_x)
{
	dir_y[0] = -1;
	dir_y[1] = 1;
	dir_y[2] = 0;
	dir_y[3] = 0;
	dir_x[0] = 0;
	dir_x[1] = 0;
	dir_x[2] = -1;
	dir_x[3] = 1;
}

int	flood_fill_region(t_game *g, char **visited, int y, int x)
{
	int		i;
	int		dir_y[4];
	int		dir_x[4];
	char	c;

	if (y < 0 || x < 0 || y >= g->map_height || x >= g->map_width)
		return (0);
	c = g->map[y][x];
	if (c == ' ' || c == '\0' || (!visited[y][x] && c == '1'))
		return (c == '1');
	if (visited[y][x])
		return (1);
	visited[y][x] = 1;
	init_dirs(dir_y, dir_x);
	i = 0;
	while (i < 4)
	{
		if (!flood_fill_region(g, visited, y + dir_y[i], x + dir_x[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	check_cell(t_game *game, char **visited, int y, int x)
{
	char	c;

	c = game->map[y][x];
	if (!is_valid_map_char(c))
	{
		printf("Error\nInvalid character in map\n");
		return (0);
	}
	if (is_walkable(c) && !visited[y][x]
		&& !flood_fill_region(game, visited, y, x))
	{
		printf("Error\nMap is not closed around floor/player\n");
		return (0);
	}
	return (1);
}

static int	validate_map_cells(t_game *game, char **visited, int *player_count)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map_height)
	{
		x = 0;
		while (x < game->map_width)
		{
			if (!check_cell(game, visited, y, x))
				return (0);
			if (is_player(game->map[y][x]))
				(*player_count)++;
			x++;
		}
		y++;
	}
	return (1);
}

int	check_map_closed(t_game *game)
{
	char	**visited;
	int		player_count;

	visited = alloc_visited(game);
	if (!visited)
		return (printf("Error\nMalloc failed\n"), 0);
	player_count = 0;
	if (!validate_map_cells(game, visited, &player_count))
	{
		free_visited(visited, game->map_height);
		return (0);
	}
	free_visited(visited, game->map_height);
	if (player_count != 1)
		return (printf("Error\nMap must contain exactly one player\n"), 0);
	return (1);
}
