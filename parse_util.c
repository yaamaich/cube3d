/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 20:04:30 by yaamaich          #+#    #+#             */
/*   Updated: 2026/03/18 20:10:56 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	set_color_type(t_game *game, char type, int col)
{
	if (type == 'F')
		game->color_floor = col;
	else
		game->color_ceiling = col;
}

void	find_player_in_line(t_game *game, char *line)
{
	int	x;

	x = 0;
	while (line[x])
	{
		if (line[x] == 'N' || line[x] == 'S'
			|| line[x] == 'E' || line[x] == 'W')
		{
			game->player_start_x = x;
			game->player_start_y = game->map_height;
			game->player_start_dir = line[x];
		}
		x++;
	}
}
