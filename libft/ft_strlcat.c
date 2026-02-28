/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamddah <aamddah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:08:10 by aamddah           #+#    #+#             */
/*   Updated: 2024/11/05 16:39:30 by aamddah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t			ld;
	size_t			ls;
	unsigned int	len_for_src;
	unsigned int	i;

	if (destsize == 0)
		return (ft_strlen(src));
	ld = ft_strlen(dest);
	ls = ft_strlen(src);
	i = 0;
	if (ld >= destsize)
		return (ls + destsize);
	len_for_src = destsize - ld - 1;
	if (len_for_src > 0)
	{
		while (len_for_src > i && src[i] != '\0')
		{
			dest [ld + i] = src [i];
			i++;
		}
		dest [ld + i] = '\0';
	}
	return (ls + ld);
}
