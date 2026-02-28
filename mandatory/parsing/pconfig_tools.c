/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pconfig_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamddah <aamddah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 11:41:51 by aamddah           #+#    #+#             */
/*   Updated: 2025/09/21 11:41:51 by aamddah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	ft_free(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

void	free_config(t_config *config)
{
	if (ft_strlen(config->north_texture_path))
	{
		ft_free(&config->north_texture_path);
	}
	if (ft_strlen(config->south_texture_path))
	{
		ft_free(&config->south_texture_path);
	}
	if (ft_strlen(config->west_texture_path))
	{
		ft_free(&config->west_texture_path);
	}
	if (ft_strlen(config->east_texture_path))
	{
		ft_free(&config->east_texture_path);
	}
}

int	is_config(char *line)
{
	return (ft_strncmp(line, "NO ", 3) == 0 
		|| ft_strncmp(line, "SO ", 3) == 0 
		|| ft_strncmp(line, "WE ", 3) == 0 
		|| ft_strncmp(line, "EA ", 3) == 0 
		||ft_strncmp(line, "F ", 2) == 0 
		|| ft_strncmp(line, "C ", 2) == 0);
}

int	is_config_complete(t_config *config)
{
	return (config->config_count == 6 
		&& config->north_texture_path && config->south_texture_path 
		&& config->west_texture_path && config->east_texture_path 
		&& config->floor_r != -1 && config->ceiling_r != -1);
}

int	check_config_done(t_data *data_prs, int *done)
{
	if (!is_config_complete(data_prs->config))
	{
		ft_putstr_fd("Error\n in configuration\n", 2);
		close(data_prs->fd);
		return (1);
	}
	*done = 1;
	return (0);
}
