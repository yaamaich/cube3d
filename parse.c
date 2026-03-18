/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 15:19:21 by albelaiz          #+#    #+#             */
/*   Updated: 2026/03/18 10:38:33 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_parse_error(t_game *game)
{
	if (!game->parse_error)
		printf("Error\n");
	game->parse_error = 1;
}

static int	is_space_tab(char c)
{
	return (c == ' ' || c == '\t');
}

static int	is_map_line(const char *line)
{
	int	i;
	int	has_non_space;

	i = 0;
	has_non_space = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] != ' ' && line[i] != '0' && line[i] != '1'
			&& line[i] != 'N' && line[i] != 'S'
			&& line[i] != 'E' && line[i] != 'W')
			return (0);
		if (line[i] != ' ')
			has_non_space = 1;
		i++;
	}
	return (has_non_space);
}

static int	is_texture_id(const char *s)
{
	if ((ft_strncmp(s, "NO", 2) == 0 || ft_strncmp(s, "SO", 2) == 0
			|| ft_strncmp(s, "WE", 2) == 0 || ft_strncmp(s, "EA", 2) == 0)
		&& is_space_tab(s[2]))
		return (1);
	return (0);
}

static int	is_color_id(const char *s)
{
	if ((s[0] == 'F' || s[0] == 'C') && is_space_tab(s[1]))
		return (1);
	return (0);
}

void	parse_line(t_game *game, char *line)
{
	char	*trimmed;
	char	*map_line;

	trimmed = ft_strtrim(line, " \t\n");
	if (!trimmed)
		return (set_parse_error(game));
	if (trimmed[0] == '\0')
	{
		if (game->map_started)
			game->map_ended = 1;
		free(trimmed);
		return ;
	}
	if (game->map_ended)
		return (free(trimmed), set_parse_error(game));
	if (is_texture_id(trimmed))
	{
		if (game->map_started)
			return (free(trimmed), set_parse_error(game));
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
			return (free(trimmed), set_parse_error(game));
		if (trimmed[0] == 'F')
			parse_color(game, trimmed, 'F');
		else
			parse_color(game, trimmed, 'C');
	}
	else if (is_map_line(line))
	{
		if (!game->map_started)
		{
			if (game->cfg_mask != CFG_ALL)
				return (free(trimmed), set_parse_error(game));
			game->map_started = 1;
		}
		map_line = ft_strtrim(line, "\n");
		if (!map_line)
			return (free(trimmed), set_parse_error(game));
		pars_map_line(game, map_line);
		free(map_line);
	}
	else
		set_parse_error(game);
	free(trimmed);
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
	{
		free(path);
		return (set_parse_error(game));
	}
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
	if ((type == 'N' && !game->path_no) || (type == 'S' && !game->path_so)
		|| (type == 'W' && !game->path_we) || (type == 'E' && !game->path_ea))
		set_parse_error(game);
	free(path);
}

void	parse_color(t_game *game, char *line, char type)
{
	int		col;

	if ((type == 'F' && (game->cfg_mask & CFG_F))
		|| (type == 'C' && (game->cfg_mask & CFG_C)))
		return (set_parse_error(game));
	if (!parse_rgb_strict(line + 2, &col))
		return (set_parse_error(game));
	set_color_type(game, type, col);
	if (type == 'F')
		game->cfg_mask |= CFG_F;
	else
		game->cfg_mask |= CFG_C;
}

void	pars_map_line(t_game *game, char *line)
{
	char	**new_map;
	int		i;
	int		len;

	new_map = malloc(sizeof(char *) * (game->map_height + 1));
	if (!new_map)
		return ;
	i = 0;
	while (i < game->map_height)
	{
		new_map[i] = game->map[i];
		i++;
	}
	new_map[game->map_height] = ft_strdup(line);
	free(game->map);
	game->map = new_map;
	len = (int)ft_strlen(line);
	if (len > game->map_width)
		game->map_width = ft_strlen(line);
	find_player_in_line(game, line);
	game->map_height++;
}
