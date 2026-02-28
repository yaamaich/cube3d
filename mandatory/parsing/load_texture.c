/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamddah <aamddah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 11:31:36 by aamddah           #+#    #+#             */
/*   Updated: 2025/09/21 11:31:36 by aamddah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

mlx_texture_t	*ft_load_to_image(t_data *game, char *path, int i)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png(path);
	if (!texture)
	{
		ft_putstr_fd("Error\n loading png\n", 2);
		return (NULL);
	}
	game->texs[i] = texture;
	return (texture);
}

int	ft_init_image(t_data *game)
{
	if (!ft_load_to_image(game, game->config->north_texture_path, 0))
		return (1);
	if (!ft_load_to_image(game, game->config->south_texture_path, 1))
		return (1);
	if (!ft_load_to_image(game, game->config->west_texture_path, 2))
		return (1);
	if (!ft_load_to_image(game, game->config->east_texture_path, 3))
		return (1);
	return (0);
}
