/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vmap_tools3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamddah <aamddah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 11:57:20 by aamddah           #+#    #+#             */
/*   Updated: 2025/10/04 15:16:14 by aamddah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

void	init_array(int array[4][2])
{
	array[0][0] = 0;
	array[0][1] = -1;
	array[1][0] = 0;
	array[1][1] = 1;
	array[2][0] = -1;
	array[2][1] = 0;
	array[3][0] = 1;
	array[3][1] = 0;
}

int	longest_line(char **map)
{
	int		i;
	size_t	c;

	i = 0;
	c = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) > c)
			c = ft_strlen(map[i]);
		i++;
	}
	return (c);
}

int	check_color(char *line)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (line[i])
	{
		if (line[i] != ',' && !ft_isdigit(line[i]))
		{
			return (0);
		}
		if (line[i] == ',')
			c++;
		i++;
	}
	if (c != 2)
		return (0);
	return (c);
}
