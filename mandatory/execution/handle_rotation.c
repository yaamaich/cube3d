/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_rotation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhamdaou <jhamdaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 12:26:00 by jhamdaou          #+#    #+#             */
/*   Updated: 2025/10/11 12:26:11 by jhamdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	rotate_left(t_data *data)
{
	data->angle -= data->rotation_speed;
	if (data->angle < 0)
		data->angle += 360;
}

void	rotate_right(t_data *data)
{
	data->angle += data->rotation_speed;
	if (data->angle >= 360)
		data->angle -= 360;
}
