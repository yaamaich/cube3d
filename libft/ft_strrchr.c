/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamddah <aamddah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:12:00 by aamddah           #+#    #+#             */
/*   Updated: 2024/11/05 17:02:27 by aamddah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*s;

	s = (char *)str;
	while (*s != '\0')
	{
		s++;
	}
	while (*s != (char)c && s != str)
	{
		s--;
	}
	if (*s == (char)c)
	{
		return (s);
	}
	return (NULL);
}
