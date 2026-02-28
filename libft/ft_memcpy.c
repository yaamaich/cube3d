/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamddah <aamddah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:02:52 by aamddah           #+#    #+#             */
/*   Updated: 2024/11/07 13:11:20 by aamddah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t num)
{
	size_t	i;
	char	*s;
	char	*d;

	if (src == dest)
		return (dest);
	i = 0;
	s = (char *)src;
	d = (char *)dest;
	while (i < num)
	{
		(d)[i] = s[i];
		i++; 
	}
	return (dest);
}
