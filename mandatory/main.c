/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamddah <aamddah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 11:58:14 by aamddah           #+#    #+#             */
/*   Updated: 2025/09/24 11:58:14 by aamddah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mandatory/includes/cub.h"

void	handle_es(mlx_key_data_t keydata, void *param)
{
	t_data	*game;

	game = param;
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
		{
			free_textures_arr(game);
			free_map(game->map, game->line_count);
			free_config(game->config);
			mlx_close_window(game->mlx);
			exit(0);
		}
	}
}

int	init_struct(char *str, t_data *data, t_config *config)
{
	data->mlx = mlx_init(WIN_W, WIN_H, "Cub3D", false);
	check_name(str, data);
	data->config = config;
	data->config->floor_r = -1;
	data->config->ceiling_r = -1;
	data->line_count = 0;
	if (!data->mlx || !map_to_array(data) || ft_init_image(data))
	{
		free_map(data->map, data->line_count);
		delete_textures(data);
		free_config(data->config);
		mlx_terminate(data->mlx);
		return (1);
	}
	if (validate_map(data->map, data->line_count))
	{
		mlx_terminate(data->mlx);
		delete_textures(data);
		free_map(data->map, data->line_count);
		return (free_config(config), 1);
	}
	return (0);
}

void	game_loop(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	render_frame(data, 0, 0);
	handle_movement(data);
}

void	init_s(t_data *data)
{
	data->screenwidth = WIN_W;
	data->screenheight = WIN_H;
	data->fov = 60;
}

int	main(int ac, char **av)
{
	t_config	config;
	t_data		data;

	ft_memset(&config, 0, sizeof(config));
	ft_memset(&data, 0, sizeof(data));
	if (ac != 2)
	{
		ft_putstr_fd("Usage: ./cub3D <map_file.cub>\n", 2);
		return (1);
	}
	if (init_struct(av[1], &data, &config))
		return (1);
	init_s(&data);
	data.img = mlx_new_image(data.mlx, WIN_W, WIN_H);
	if (!data.img)
		return (1);
	init_player_pos(&data, data.map);
	mlx_image_to_window(data.mlx, data.img, 0, 0);
	init_textures(&data);
	mlx_close_hook(data.mlx, free_textures_arr, &data);
	mlx_key_hook(data.mlx, handle_es, &data);
	mlx_loop_hook(data.mlx, &game_loop, &data);
	mlx_loop(data.mlx);
	mlx_terminate(data.mlx);
	return (free_config(data.config), free_map(data.map, data.line_count), 0);
}
