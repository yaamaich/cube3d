/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamddah <aamddah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:18:34 by aamddah           #+#    #+#             */
/*   Updated: 2024/11/05 16:32:21 by aamddah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*p;
	size_t	s1_lenth;

	s1_lenth = ft_strlen(s1);
	p = (char *)malloc((s1_lenth +1) * sizeof(char));
	if (!p)
	{
		return (p);
	}
	ft_memcpy(p, s1, s1_lenth);
	p[s1_lenth] = '\0';
	return (p);
}
