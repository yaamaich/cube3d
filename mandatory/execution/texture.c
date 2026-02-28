/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamddah <aamddah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 11:01:09 by aamddah           #+#    #+#             */
/*   Updated: 2025/10/12 12:59:00 by aamddah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	free_textures_arr(void *gam)
{
	t_data	*game;
	int		y;

	game = (t_data *)gam;
	y = 0;
	while (y < game->walls_textures[0].height)
		free(game->walls_textures[0].arr[y++]);
	free(game->walls_textures[0].arr);
	y = 0;
	while (y < game->walls_textures[1].height)
		free(game->walls_textures[1].arr[y++]);
	free(game->walls_textures[1].arr);
	y = 0;
	while (y < game->walls_textures[2].height)
		free(game->walls_textures[2].arr[y++]);
	free(game->walls_textures[2].arr);
	y = 0;
	while (y < game->walls_textures[3].height)
		free(game->walls_textures[3].arr[y++]);
	free(game->walls_textures[3].arr);
	delete_textures(gam);
}

static uint32_t	ft_pixel(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	return (((uint32_t)r << 24)
		| ((uint32_t)g << 16)
		| ((uint32_t)b << 8)
		| (uint32_t)a);
}

void	render_texture_stripe(mlx_image_t *img, t_texture *tex_data, 
int x, t_data *data)
{
	int			y;
	int			texy;
	double		step;
	double		texpos;
	uint32_t	color;

	step = (double)tex_data->height / data->wall_height;
	texpos = (data->draw_start - (int)(WIN_H / 2) 
			+ (data->wall_height / 2)) * step;
	y = data->draw_start;
	while (y < data->draw_end)
	{
		texy = (int)texpos;
		if (texy < 0)
			texy = 0;
		else if (texy >= tex_data->height)
			texy = tex_data->height - 1;
		texpos += step;
		color = tex_data->arr[texy][data->texx];
		mlx_put_pixel(img, x, y, color);
		y++;
	}
}

static void	draw_ce_fl(t_data *game, int x, int y, char f)
{
	if (f == 'c')
	{
		mlx_put_pixel(game->img, x, y,
			ft_pixel(
				game->config->ceiling_r,
				game->config->ceiling_g,
				game->config->ceiling_b,
				255
				));
	}
	else if (f == 'f')
	{
		mlx_put_pixel(game->img, x, y,
			ft_pixel(
				game->config->floor_r,
				game->config->floor_g,
				game->config->floor_b,
				255));
	}
}

void	render_frame(t_data *data, int x, int y)
{
	t_texture	*tex;

	x = 0;
	y = 0;
	while (x < data->screenwidth)
	{
		raycast(data, x);
		y = 0;
		while (y < data->draw_start)
		{
			draw_ce_fl(data, x, y, 'c');
			y++;
		}
		tex = &data->walls_textures[data->texnum];
		render_texture_stripe(data->img, tex, x, data);
		y = data->draw_end;
		while (y < data->screenheight)
		{
			draw_ce_fl(data, x, y, 'f');
			y++;
		}
		x++;
	}
}
