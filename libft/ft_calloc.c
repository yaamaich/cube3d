/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamddah <aamddah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:17:48 by aamddah           #+#    #+#             */
/*   Updated: 2024/10/31 16:39:32 by aamddah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*p;
	size_t			to_size;

	to_size = count * size;
	if (size != 0 && to_size / size != count)
	{
		return (NULL);
	}
	if (to_size == 0)
		return (malloc(0));
	p = malloc(to_size);
	if (!p)
	{
		return (NULL);
	}
	ft_bzero(p, to_size);
	return (p);
}
