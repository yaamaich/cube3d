/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamddah <aamddah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:21:44 by aamddah           #+#    #+#             */
/*   Updated: 2024/11/07 11:57:58 by aamddah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_word(char const *s, char c)
{
	size_t	i;
	int		n;
	char	f;

	i = 0;
	n = 0;
	f = 'n';
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
		{
			i++;
			f = 'n';
		}
		while (s[i] != c && s[i] != '\0')
		{
			i++;
			f = 'w';
		}
		if (f == 'w')
			n++;
	}
	return (n);
}

static size_t	ft_strlensp(char const *s, size_t start, char c)
{
	size_t	i;

	i = 0;
	while (s[start] != '\0' && s[start] != c)
	{
		start++;
		i++;
	}
	return (i);
}

static void	ft_free(char **ptr, size_t	i)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		if (ptr[j])
			free(ptr[j]);
		j++;
	}
	free(ptr);
}

static char	**ft_put_word(char const *s, char **ptr, char c, size_t i)
{
	unsigned int	start;
	unsigned int	end;

	start = 0;
	end = 0;
	while (s[end] != '\0')
	{
		while (s[end] == c && s[end] != '\0')
			end++;
		start = end;
		if (s[end] != c && s[end] != '\0')
		{
			end = ft_strlensp(s, end, c);
			ptr[i] = ft_substr(s, start, end);
			if (!ptr[i])
			{
				ft_free(ptr, i);
				return (NULL);
			}
			end += start;
			i++;
		}
	}
	ptr[i] = NULL;
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	ptr = (char **)malloc((ft_count_word(s, c) + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	return (ft_put_word(s, ptr, c, i));
}
