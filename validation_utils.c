/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 20:36:49 by yaamaich          #+#    #+#             */
/*   Updated: 2026/03/18 20:36:57 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int	is_walkable(char c)
{
	return (c == '0' || is_player(c));
}

int	is_valid_map_char(char c)
{
	return (c == '0' || c == '1' || c == ' ' || is_player(c));
}

void	free_visited(char **visited, int height)
{
	int	i;

	i = 0;
	if (!visited)
		return ;
	while (i < height)
	{
		free(visited[i]);
		i++;
	}
	free(visited);
}

char	**alloc_visited(t_game *g)
{
	char	**visited;
	int		y;

	visited = (char **)malloc(sizeof(char *) * g->map_height);
	if (!visited)
		return (NULL);
	y = 0;
	while (y < g->map_height)
	{
		visited[y] = (char *)ft_calloc(g->map_width, sizeof(char));
		if (!visited[y])
		{
			free_visited(visited, y);
			return (NULL);
		}
		y++;
	}
	return (visited);
}
