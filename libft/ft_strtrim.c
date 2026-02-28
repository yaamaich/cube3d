/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamddah <aamddah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:23:23 by aamddah           #+#    #+#             */
/*   Updated: 2024/11/08 15:23:50 by aamddah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_start(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && ft_strchr(set, s1[i]))
	{
		i++;
	}
	return (i);
}

static size_t	ft_end(char const *s1, char const *set, size_t	start)
{
	size_t	end;

	end = ft_strlen(s1) - 1;
	while (s1[end] != s1[start] && ft_strchr(set, s1[end]))
	{
		end--;
	}
	return (end + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	char	*s;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = ft_start(s1, set);
	if (s1[start] == '\0')
	{
		return (ft_strdup(""));
	}
	end = ft_end(s1, set, start);
	if (start > end)
		return (NULL);
	s = (char *)malloc(((end - start) + 1) * sizeof(char));
	if (!s)
		return (NULL);
	ft_strlcpy(s, s1 + start, (end - start) + 1);
	s[end - start] = '\0';
	return (s);
}
