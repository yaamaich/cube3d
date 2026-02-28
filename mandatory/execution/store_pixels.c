/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_pixels.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamddah <aamddah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 11:06:22 by aamddah           #+#    #+#             */
/*   Updated: 2025/10/09 20:08:13 by aamddah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	fill_single_row_pixels(uint32_t *row_arr, mlx_texture_t *texture, 
		size_t row_idx)
{
	size_t	x;
	size_t	y;
	size_t	base;
	t_pixel	pixel;

	x = 0;
	y = texture->width - 1;
	while (x < texture->width)
	{
		base = (row_idx * texture->width * 4) + (x * 4);
		pixel.r = texture->pixels[base + 0];
		pixel.g = texture->pixels[base + 1];
		pixel.b = texture->pixels[base + 2];
		pixel.a = texture->pixels[base + 3];
		row_arr[y] = ((uint32_t)pixel.r << 24) | ((uint32_t)pixel.g << 16) 
			| ((uint32_t)pixel.b << 8)
			| (uint32_t)pixel.a;
		x++;
		y--;
	}
}

uint32_t	**alloc_textures(mlx_texture_t *texture, t_texture *tex_data)
{
	uint32_t	**arr;
	int			y;

	tex_data->width = texture->width;
	tex_data->height = texture->height;
	arr = malloc(sizeof(uint32_t *) * tex_data->height);
	if (!arr)
		return (NULL);
	y = 0;
	while (y < tex_data->height)
	{
		arr[y] = malloc(sizeof(uint32_t) * tex_data->width);
		if (!arr[y])
		{
			while (--y >= 0)
				free(arr[y]);
			free(arr);
			return (NULL);
		}
		y++;
	}
	return (arr);
}

void	mlx_text_to_arr(mlx_texture_t *texture, t_texture *texture_data)
{
	uint32_t	**arr;
	size_t		j;

	if (!texture || !texture_data)
		return ;
	arr = alloc_textures(texture, texture_data);
	if (!arr)
		return ;
	j = 0;
	while (j < texture->height)
	{
		fill_single_row_pixels(arr[j], texture, j);
		j++;
	}
	texture_data->arr = arr;
}

void	delete_textures(void *gam)
{
	t_data	*data;

	data = (t_data *)gam;
	if (data->texs[0])
		mlx_delete_texture(data->texs[0]);
	if (data->texs[1])
		mlx_delete_texture(data->texs[1]);
	if (data->texs[2])
		mlx_delete_texture(data->texs[2]);
	if (data->texs[3])
		mlx_delete_texture(data->texs[3]);
}

void	init_textures(t_data *game)
{
	mlx_text_to_arr(game->texs[0], &game->walls_textures[0]);
	mlx_text_to_arr(game->texs[1], &game->walls_textures[1]);
	mlx_text_to_arr(game->texs[2], &game->walls_textures[2]);
	mlx_text_to_arr(game->texs[3], &game->walls_textures[3]);
}
