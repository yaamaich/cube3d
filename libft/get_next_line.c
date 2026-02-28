/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamddah <aamddah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 15:47:50 by aamddah           #+#    #+#             */
/*   Updated: 2025/09/07 13:00:38 by aamddah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <sys/syslimits.h>

static char	*ft_free_malloc(char *s1, char *s2, char **s3, char f)
{
	if (s2)
	{
		free(s2);
		s2 = NULL;
	}
	if (f == 'r')
		return (s1);
	if (s1)
	{
		free(s1);
		s1 = NULL;
	}
	if (f == 'y')
	{
		*s3 = (char *)malloc(BUFFER_SIZE +1 * sizeof(char));
		if (!*s3)
			return (NULL);
		return (*s3);
	}
	return (NULL);
}

static char	*ft_take_all(char *str, int fd)
{
	int		d;
	char	*buff;
	char	*tmp;

	if ((ft_free_malloc(NULL, NULL, &buff, 'y')) == NULL)
		return (free(str), str = NULL, buff = NULL, NULL);
	d = read(fd, buff, BUFFER_SIZE);
	while (d > 0)
	{
		buff[d] = '\0';
		tmp = ft_strjoin_get(str, buff);
		free(str);
		str = NULL;
		if (!tmp)
			return (free(buff), buff = NULL, NULL);
		str = tmp;
		if (ft_strchr(str, '\n'))
			break ;
		d = read(fd, buff, BUFFER_SIZE);
	}
	if (d != -1 && str && str[0] != '\0')
		return (ft_free_malloc(str, buff, &buff, 'r'));
	return (ft_free_malloc(str, buff, &buff, 'n'));
}

static char	*ft_just_line(char *str)
{
	size_t	i;
	char	*line;

	i = 0;
	while (str[i])
	{
		if (str [i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	line = ft_strndup(str, i);
	if (!line)
		return (NULL);
	return (line);
}

static char	*ft_get_rest(char *str)
{
	size_t	i;
	char	*rest;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	rest = ft_strndup(str + i, 0);
	if (!rest)
		return (free(str), str = NULL, NULL);
	return (free(str), str = NULL, rest);
}

char	*get_next_line(int fd)
{
	static char	*str[1024];
	char		*line;

	str[fd] = ft_take_all(str[fd], fd);
	if (!str[fd])
		return (NULL);
	line = ft_just_line(str[fd]);
	if (!line)
	{
		return (free(str[fd]), str[fd] = NULL);
	}
	str[fd] = ft_get_rest(str[fd]);
	if (!str[fd])
		return (free(line), line = NULL, NULL);
	return (line);
}
