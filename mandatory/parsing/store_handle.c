/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamddah <aamddah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 11:50:08 by aamddah           #+#    #+#             */
/*   Updated: 2025/09/21 11:50:08 by aamddah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"
#include <stdio.h>
#include <string.h>

int	handle_map(char *trimmed, t_data *data_prs)
{
	if (!is_map_line(trimmed))
	{
		ft_putstr_fd("Error\n Invalid map line\n", 2);
		close(data_prs->fd); 
		return (1);
	}
	data_prs->map[data_prs->line_count] = ft_strdup(trimmed);
	(data_prs->line_count)++;
	if (data_prs->line_count >= 999)
	{
		ft_putstr_fd("Error\n Map too large\n", 2);
		close(data_prs->fd);
		return (1);
	}
	return (0);
}

static int	handle_config(char *trimmed, t_data *data_prs)
{
	if (parse_config(trimmed, data_prs->config))
	{
		close(data_prs->fd);
		return (1);
	}
	return (0);
}

int	store_config(t_data *data_prs, char *trimmed, int *done)
{
	if (!*done && is_config(trimmed))
	{
		if (handle_config(trimmed, data_prs))
			return (0);
	}
	else
	{
		if (!*done && check_config_done(data_prs, done))
			return (0);
		if (handle_map(trimmed, data_prs))
		{
			return (0);
		}
	}
	return (1);
}

int	store_map(t_data *data_prs, char *line, char **trimmed, int *done)
{
	line = ft_strdup("nice");
	while (line)
	{
		ft_free(&line);
		line = get_next_line(data_prs->fd);
		if (!line)
			break ;
		get_trimmed(line, trimmed);
		if (!(*trimmed))
			return (ft_free(&line), 1);
		if (!(**trimmed) || empty_line(*trimmed))
		{
			if (data_prs->line_count > 0)
				return (ft_putstr_fd("Error\n Empty line\n", 2), 
					ft_free(&line), 1);
			continue ;
		}
		if (!store_config(data_prs, *trimmed, done))
			return (ft_free(&line), 1);
	}
	if (*trimmed && !(**trimmed) && data_prs->line_count > 0)
		return (ft_putstr_fd("Error\n Empty line\n", 2), ft_free(trimmed), 1);
	data_prs->map[data_prs->line_count] = NULL;
	return (close(data_prs->fd), ft_free(trimmed), 0);
}

char	**map_to_array(t_data *data_prs)
{
	char	*line;
	char	*trimmed;
	int		done[1];

	done[0] = 0;
	line = NULL;
	trimmed = NULL;
	data_prs->map = malloc(sizeof(char *) * 1000);
	if (!data_prs->map)
		return (NULL);
	data_prs->fd = open(data_prs->map_path, O_RDONLY);
	if (data_prs->fd == -1)
	{
		perror("Error\n opning file\n");
		return (NULL);
	}
	data_prs->line_count = 0;
	if (store_map(data_prs, line, &trimmed, done))
		return (ft_free(&trimmed), NULL);
	return (data_prs->map);
}
