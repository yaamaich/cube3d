/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamddah <aamddah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:14:30 by aamddah           #+#    #+#             */
/*   Updated: 2024/11/07 13:08:30 by aamddah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t				i;
	unsigned char		ch;
	unsigned const char	*s;

	i = 0;
	ch = (unsigned char)c;
	s = (unsigned const char *)str;
	while (i < n)
	{
		if (*s == ch)
		{
			return ((void *)s);
		}
		i++;
		s++;
	}
	return (NULL);
}
