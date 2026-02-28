/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycastJihad.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamdaou <jhamdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 12:23:06 by jhamdaou          #+#    #+#             */
/*   Updated: 2025/10/11 12:23:06 by jhamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	init_player_pos(t_data *d, char **map)
{
	d->y = 0;
	while (map[d->y])
	{
		d->x = 0;
		while (map[d->y][d->x])
		{
			if (map[d->y][d->x] == 'N' || map[d->y][d->x] == 'S' ||
			map[d->y][d->x] == 'W' || map[d->y][d->x] == 'E')
			{
				d->pos_x = d->x + 0.5;
				d->pos_y = d->y + 0.5;
				if (map[d->y][d->x] == 'S')
					d->angle = 90;
				else if (map[d->y][d->x] == 'N')
					d->angle = 270;
				else if (map[d->y][d->x] == 'E')
					d->angle = 0;
				else if (map[d->y][d->x] == 'W')
					d->angle = 180;
			}
			d->x++;
		}
		d->y++;
	}
}

void	set_texx(t_data *data)
{
	if (data->side == 0 && data->ray_dir_x > 0)
		data->texx = data->texs[data->texnum]->width - data->texx - 1;
	if (data->side == 1 && data->ray_dir_y < 0)
		data->texx = data->texs[data->texnum]->width - data->texx - 1;
}

void	set_texture(t_data *data)
{
	double	wallx;

	if (data->side == 0)
		wallx = data->pos_y + data->perp_wall_dist * data->ray_dir_y;
	else
		wallx = data->pos_x + data->perp_wall_dist * data->ray_dir_x;
	wallx -= floor(wallx);
	data->texx = (int)(wallx * (double)data->texs[data->texnum]->width);
	set_texx(data);
	if (data->side == 0 && data->ray_dir_x > 0) 
		data->texnum = 0;
	else if (data->side == 0 && data->ray_dir_x < 0) 
		data->texnum = 1;
	else if (data->side == 1 && data->ray_dir_y > 0) 
		data->texnum = 2;
	else
		data->texnum = 3;
	if (data->side == 0)
		data->perp_wall_dist = (data->map_x - data->pos_x
				+ (int)((1 - data->step_x) / 2)) / data->ray_dir_x;
	else
		data->perp_wall_dist = (data->map_y - data->pos_y
				+ (int)((1 - data->step_y) / 2)) / data->ray_dir_y;
}

float	cast_single_ray(t_data *data, float ray_angle)
{
	data->ray_rad = deg_to_rad(ray_angle);
	data->ray_dir_x = cos(data->ray_rad);
	data->ray_dir_y = sin(data->ray_rad);
	data->map_x = (int)(data->pos_x);
	data->map_y = (int)(data->pos_y);
	data->hit = false;
	data->side = 0;
	set_delta(data);
	set_side_dist(data);
	finding_hit(data);
	set_texture(data);
	return (data->perp_wall_dist);
}

void	raycast(t_data	*data, int x)
{
	float	angle_diff;

	data->start_angle = data->angle - (data->fov / 2);
	data->angle_step = data->fov / WIN_W;
	data->ray_angle = data->start_angle + (x * data->angle_step);
	data->wall_distance = cast_single_ray(data, data->ray_angle);
	angle_diff = deg_to_rad(data->ray_angle - data->angle);
	data->wall_distance *= cos(angle_diff);
	data->wall_height = (int)(WIN_H / data->wall_distance);
	data->draw_start = (WIN_H - data->wall_height) / 2;
	data->draw_end = data->draw_start + data->wall_height;
	if (data->draw_start < 0)
		data->draw_start = 0;
	if (data->draw_end >= WIN_H)
		data->draw_end = WIN_H;
}
