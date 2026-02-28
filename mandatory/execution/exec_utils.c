/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamdaou <jhamdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 12:24:26 by jhamdaou          #+#    #+#             */
/*   Updated: 2025/10/14 14:18:39 by jhamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

float	deg_to_rad(float degree)
{
	return (degree * PI / 180);
}

void	set_delta(t_data *data)
{
	if (data->ray_dir_x == 0)
		data->delta_x = INFINITY;
	else
		data->delta_x = fabs(1 / data->ray_dir_x);
	if (data->ray_dir_y == 0)
		data->delta_y = INFINITY;
	else
		data->delta_y = fabs(1 / data->ray_dir_y);
}

void	set_side_dist(t_data *d)
{
	if (d->ray_dir_x < 0)
	{
		d->side_dist_x = (d->pos_x - (int)(d->pos_x)) * d->delta_x;
		d->step_x = -1;
	}
	else
	{
		d->side_dist_x = ((int)(d->pos_x) + 1.0 - d->pos_x) * d->delta_x;
		d->step_x = 1;
	}
	if (d->ray_dir_y < 0)
	{
		d->side_dist_y = (d->pos_y - (int)(d->pos_y)) * d->delta_y;
		d->step_y = -1;
	}
	else
	{
		d->side_dist_y = ((int)(d->pos_y) + 1.0 - d->pos_y) * d->delta_y;
		d->step_y = 1;
	}
}

void	finding_hit(t_data *data)
{
	while (!data->hit)
	{
		if (data->side_dist_x < data->side_dist_y)
		{
			data->side_dist_x += data->delta_x;
			data->map_x += data->step_x;
			data->side = 0;
		}
		else
		{
			data->side_dist_y += data->delta_y;
			data->map_y += data->step_y ;
			data->side = 1;
		}
		if (data->map[data->map_y][data->map_x] == '1')
			data->hit = true;
	}
}

int	is_wall(t_data *data, float x, float y)
{
	if (data->map[(int)y][(int)x] != '1')
		return (1);
	return (0);
}
