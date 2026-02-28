/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamddah <aamddah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 11:33:00 by aamddah           #+#    #+#             */
/*   Updated: 2025/09/21 11:33:00 by aamddah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	exstract_value(int *values, char *start)
{
	int		i;
	int		p;
	char	*tmp;

	i = 0;
	p = 0;
	tmp = start;
	while (*tmp && i < 3)
	{
		while (i != 2 && tmp[p] != ',' && tmp[p] != '\0')
			p++;
		if (i != 2)
		{
			p++;
			tmp[p - 1] = '\0';
		}
		values[i] = ft_atoi(tmp);
		if (values[i] < 0 || values[i++] > 255)
			return (1);
		tmp += p;
		p = 0;
	}
	if (i != 3)
		return (1);
	return (0);
}

int	parse_color(char *line, int *r, int *g, int *b)
{
	char	*start;
	char	*tmp;
	int		values[3];

	if (*r != -1)
		return (1);
	if (!check_color(line + 2))
		return (1);
	start = ft_strdup(line + 2);
	tmp = start;
	while (*tmp == ' ')
		tmp++;
	if (exstract_value(values, tmp))
		return (ft_free(&start), 1);
	ft_free(&tmp);
	*r = values[0];
	*g = values[1];
	return (*b = values[2], 0);
}

int	color_part(char *line, t_config *config)
{
	if (ft_strncmp(line, "F ", 2) == 0)
	{
		if (parse_color(line, &config->floor_r, 
				&config->floor_g, &config->floor_b))
			return (ft_putstr_fd("Error\n Invalid floor color\n", 2), 1);
		config->config_count++;
	}
	else if (ft_strncmp(line, "C ", 2) == 0)
	{
		if (parse_color(line, &config->ceiling_r, 
				&config->ceiling_g, &config->ceiling_b))
			return (ft_putstr_fd("Error\n Invalid ceiling color\n", 2), 1);
		config->config_count++;
	}
	return (0);
}

int	parse_texture(char *line, char **texture)
{
	char	*start;

	start = line + 3;
	while (*start == ' ')
		start++;
	if (!*start)
		return (1);
	if (*texture != NULL)
	{
		return (0);
	}
	*texture = malloc(ft_strlen(start) + 1);
	if (!*texture)
		return (1);
	ft_strlcpy(*texture, start, ft_strlen(start) + 1);
	return (0);
}

int	parse_config(char *line, t_config *config)
{
	int		i;
	char	*conf[5];
	char	**tex[10];

	conf[0] = "NO ";
	conf[1] = "SO ";
	conf[2] = "WE ";
	conf[3] = "EA ";
	conf[4] = NULL;
	tex[0] = &config->north_texture_path;
	tex[1] = &config->south_texture_path;
	tex[2] = &config->west_texture_path;
	tex[3] = &config->east_texture_path;
	tex[4] = NULL;
	i = 0;
	while (conf[i] && (ft_strncmp(line, conf[i], 3) != 0))
		i++;
	if (conf[i] && !ft_strncmp(line, conf[i], 3) && 
		parse_texture(line, tex[i]))
		return (ft_putstr_fd("Error\n Invalid texture\n", 2), 1);
	if (conf[i] && !ft_strncmp(line, conf[i], 3))
		return (config->config_count++, 0);
	return (color_part(line, config));
}
