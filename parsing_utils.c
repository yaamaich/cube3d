/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaamaich <yaamaich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 19:54:05 by yaamaich          #+#    #+#             */
/*   Updated: 2026/03/18 19:54:41 by yaamaich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_parse_error(t_game *game)
{
	if (!game->parse_error)
		printf("Error\n");
	game->parse_error = 1;
}

int	is_space_tab(char c)
{
	return (c == ' ' || c == '\t');
}

int	is_map_line(const char *line)
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

int	is_texture_id(const char *s)
{
	if ((ft_strncmp(s, "NO", 2) == 0 || ft_strncmp(s, "SO", 2) == 0
			|| ft_strncmp(s, "WE", 2) == 0 || ft_strncmp(s, "EA", 2) == 0)
		&& is_space_tab(s[2]))
		return (1);
	return (0);
}

int	is_color_id(const char *s)
{
	if ((s[0] == 'F' || s[0] == 'C') && is_space_tab(s[1]))
		return (1);
	return (0);
}
