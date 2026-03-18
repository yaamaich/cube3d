/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:19:21 by albelaiz          #+#    #+#             */
/*   Updated: 2026/03/18 20:06:31 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	parse_config(t_game *game, char *trimmed)
{
	if (is_texture_id(trimmed))
	{
		if (game->map_started)
			return (set_parse_error(game));
		if (ft_strncmp(trimmed, "NO", 2) == 0)
			pars_texture(game, trimmed, 'N');
		else if (ft_strncmp(trimmed, "SO", 2) == 0)
			pars_texture(game, trimmed, 'S');
		else if (ft_strncmp(trimmed, "WE", 2) == 0)
			pars_texture(game, trimmed, 'W');
		else if (ft_strncmp(trimmed, "EA", 2) == 0)
			pars_texture(game, trimmed, 'E');
	}
	else if (is_color_id(trimmed))
	{
		if (game->map_started)
			return (set_parse_error(game));
		if (trimmed[0] == 'F')
			parse_color(game, trimmed, 'F');
		else
			parse_color(game, trimmed, 'C');
	}
	else
		set_parse_error(game);
}

static void	parse_map_section(t_game *game, char *line)
{
	char	*map_line;

	if (!game->map_started && game->cfg_mask == CFG_ALL)
		game->map_started = 1;
	if (game->map_started)
	{
		map_line = ft_strtrim(line, "\n");
		if (map_line)
		{
			pars_map_line(game, map_line);
			free(map_line);
		}
	}
}

void	parse_line(t_game *game, char *line)
{
	char	*trimmed;

	trimmed = ft_strtrim(line, " \t\n");
	if (!trimmed)
		return (set_parse_error(game));
	if (trimmed[0] == '\0')
	{
		if (game->map_started)
			game->map_ended = 1;
		return (free(trimmed));
	}
	if (game->map_ended)
		return (free(trimmed), set_parse_error(game));
	if (is_texture_id(trimmed) || is_color_id(trimmed))
		return (parse_config(game, trimmed), free(trimmed));
	if (is_map_line(line))
		parse_map_section(game, line);
	free(trimmed);
}

static void	assign_texture_path(t_game *game, char type, char *path)
{
	if (type == 'N')
	{
		game->path_no = ft_strdup(path);
		game->cfg_mask |= CFG_NO;
	}
	else if (type == 'S')
	{
		game->path_so = ft_strdup(path);
		game->cfg_mask |= CFG_SO;
	}
	else if (type == 'W')
	{
		game->path_we = ft_strdup(path);
		game->cfg_mask |= CFG_WE;
	}
	else if (type == 'E')
	{
		game->path_ea = ft_strdup(path);
		game->cfg_mask |= CFG_EA;
	}
}

void	pars_texture(t_game *game, char *line, char type)
{
	char	*path;

	if ((type == 'N' && (game->cfg_mask & CFG_NO))
		|| (type == 'S' && (game->cfg_mask & CFG_SO))
		|| (type == 'W' && (game->cfg_mask & CFG_WE))
		|| (type == 'E' && (game->cfg_mask & CFG_EA)))
		return (set_parse_error(game));
	path = ft_strtrim(line + 3, " \t");
	if (!path || path[0] == '\0')
		return (free(path), set_parse_error(game));
	assign_texture_path(game, type, path);
	if ((type == 'N' && !game->path_no) || (type == 'S' && !game->path_so)
		|| (type == 'W' && !game->path_we) || (type == 'E' && !game->path_ea))
		set_parse_error(game);
	free(path);
}
