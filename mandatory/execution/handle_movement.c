/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamdaou <jhamdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 15:33:24 by jhamdaou          #+#    #+#             */
/*   Updated: 2025/10/14 15:48:50 by jhamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	move_up(t_data *data)
{
	float	new_x;
	float	new_y;

	data->dx = cos(data->angle_rad) * data->move_speed;
	data->dy = sin(data->angle_rad) * data->move_speed;
	new_x = data->pos_x + data->dx;
	new_y = data->pos_y + data->dy;
	if (is_walkable(data, new_x, new_y))
	{
		data->pos_x = new_x;
		data->pos_y = new_y;
	}
}

void	move_down(t_data *data)
{
	float	new_x;
	float	new_y;

	data->dx = cos(data->angle_rad) * data->move_speed;
	data->dy = sin(data->angle_rad) * data->move_speed;
	new_x = data->pos_x - data->dx;
	new_y = data->pos_y - data->dy;
	if (is_walkable(data, new_x, new_y))
	{
		data->pos_x = new_x;
		data->pos_y = new_y;
	}
}

void	move_right(t_data *data)
{
	float	new_x;
	float	new_y;

	data->dx = cos(data->angle_rad + PI / 2) * data->move_speed;
	data->dy = sin(data->angle_rad + PI / 2) * data->move_speed;
	new_x = data->pos_x + data->dx;
	new_y = data->pos_y + data->dy;
	if (is_walkable(data, new_x, new_y))
	{
		data->pos_x = new_x;
		data->pos_y = new_y;
	}
}

void	move_left(t_data *data)
{
	float	new_x;
	float	new_y;

	data->dx = cos(data->angle_rad - PI / 2) * data->move_speed;
	data->dy = sin(data->angle_rad - PI / 2) * data->move_speed;
	new_x = data->pos_x + data->dx;
	new_y = data->pos_y + data->dy;
	if (is_walkable(data, new_x, new_y))
	{
		data->pos_x = new_x;
		data->pos_y = new_y;
	}
}

void	handle_movement(t_data *data)
{
	data->move_speed = 0.05;
	data->angle_rad = deg_to_rad(data->angle);
	data->rotation_speed = 1.5;
	if (mlx_is_key_down(data->mlx, MLX_KEY_W))
		move_up(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_S))
		move_down(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_A))
		move_left(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_D))
		move_right(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_LEFT))
		rotate_left(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_RIGHT))
		rotate_right(data);
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
	{
		mlx_close_window(data->mlx);
		exit(0);
	}
}
