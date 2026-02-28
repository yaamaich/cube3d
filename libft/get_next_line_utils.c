/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamddah <aamddah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:20:17 by aamddah           #+#    #+#             */
/*   Updated: 2025/09/07 13:02:03 by aamddah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// size_t	ft_strlcpy(char	*dest, const char	*src, size_t	destsize)
// {
// 	size_t	i;

// 	i = 0;
// 	if (!dest || !src)
// 		return (0);
// 	if (destsize > 0)
// 	{
// 		while (i < destsize - 1 && src[i] != '\0')
// 		{
// 			dest[i] = src[i];
// 			i++;
// 		}
// 		dest[i] = '\0';
// 	}
// 	i = ft_strlen(src);
// 	return (i);
// }

// char	*ft_strchr(const char *str, int c)
// {
// 	char	*s;

// 	if (!str)
// 		return (NULL);
// 	s = (char *)str;
// 	while (*s != '\0' && *s != (char)c)
// 	{
// 		s++;
// 	}
// 	if (*s == (char)c)
// 	{
// 		return (s);
// 	}
// 	return (NULL);
// }

char	*ft_strndup(char *s1, int len)
{
	char	*p;
	size_t	s1_lenth;

	if (!s1)
		return (NULL);
	s1_lenth = len;
	if (len == 0)
		s1_lenth = ft_strlen(s1);
	p = (char *)malloc((s1_lenth +1) * sizeof(char));
	if (!p)
	{
		return (NULL);
	}
	ft_strlcpy(p, s1, s1_lenth + 1);
	p[s1_lenth] = '\0';
	return (p);
}

char	*ft_strjoin_get(char const *s1, char const *s2)
{
	size_t	s1_l;
	size_t	s2_l;
	size_t	total_l;
	char	*s3;

	if (!s2)
		return (NULL);
	s1_l = 0;
	if (s1)
		s1_l = ft_strlen(s1);
	s2_l = ft_strlen(s2);
	total_l = s1_l + s2_l;
	s3 = (char *)malloc((total_l + 1) * sizeof(char));
	if (!s3)
		return (NULL);
	ft_strlcpy(s3, s1, total_l + 1);
	ft_strlcpy(s3 + s1_l, s2, total_l + 1);
	return (s3);
}

// size_t	ft_strlen(const char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	if (!str)
// 		return (0);
// 	while (str[i] != '\0')
// 	{
// 		i++;
// 	}
// 	return (i);
// }
