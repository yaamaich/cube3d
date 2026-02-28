/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vmap_tools2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamddah <aamddah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 12:43:16 by aamddah           #+#    #+#             */
/*   Updated: 2025/09/21 12:43:16 by aamddah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"
#include <string.h>

void	free_map(char **map, int lines)
{
	int	i;

	if (!map)
		return ;
	i = 0;
	while (i < lines)
	{
		if (map[i])
			ft_free(&(map[i]));
		i++;
	}
	if (map)
	{
		free(map);
		map = NULL;
	}
}

int	is_spawning_orientation(char c)
{
	if (c == 'W' || c == 'S' || c == 'N' || c == 'E')
		return (1);
	return (0);
}

int	empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_isspace(line[i]))
			return (0);
		i++;
	}
	return (1);
}

void	free_path(char **str)
{
	int	i;

	i = 0;
	if (!str)
	{
		return ;
	}
	while (str[i])
	{
		free(str[i]);
		str[i++] = NULL;
	}
	free(str);
}

void	check_name(char *str, t_data *data_prs)
{
	char	*s;
	char	**s2;
	int		i;

	s2 = ft_split(str, '/');
	if (s2[1] == NULL)
	{
		i = (int)ft_strlen(str);
		s = ft_strnstr(str, ".cub", i);
	}
	else
	{
		i = ft_strlen(ft_strrchr(str, '/') + 1);
		s = ft_strnstr(ft_strrchr(str, '/') + 1, ".cub", i);
	}
	if (!s || i < 5 || *(s + 4) != '\0')
	{
		ft_putstr_fd("Error \nValid arg example: dir/map_name.cub\n", 2);
		free_path(s2);
		exit(1);
	}
	data_prs->map_path = str;
	free_path(s2);
}
