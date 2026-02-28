/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   if_walkable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamdaou <jhamdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:36:20 by jhamdaou          #+#    #+#             */
/*   Updated: 2025/10/14 15:47:11 by jhamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	check_single_point(t_data *data, float x, float y)
{
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;
	if (data->map[map_y][map_x] == '1' || data->map[map_y][map_x] == ' ')
		return (0);
	return (1);
}

int	is_walkable(t_data *data, float x, float y)
{
	float	collision_radius;

	collision_radius = 0.1;
	if (!check_single_point(data, x, y))
		return (0);
	if (!check_single_point(data, x + collision_radius, y))
		return (0);
	if (!check_single_point(data, x - collision_radius, y))
		return (0);
	if (!check_single_point(data, x, y + collision_radius))
		return (0);
	if (!check_single_point(data, x, y - collision_radius))
		return (0);
	return (1);
}
