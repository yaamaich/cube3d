/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamddah <aamddah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:19:37 by aamddah           #+#    #+#             */
/*   Updated: 2024/11/05 17:33:02 by aamddah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	size_t	sl;
	size_t	new_len;

	if (!s)
		return (NULL);
	sl = ft_strlen(s);
	new_len = len;
	if (start >= sl)
	{
		subs = (char *)malloc(sizeof(char));
		if (!subs)
			return (NULL);
		subs[0] = '\0';
		return (subs);
	}
	if (len > sl || sl - start < len)
		new_len = sl - start;
	subs = (char *)malloc((new_len + 1) * sizeof(char));
	if (!subs)
		return (NULL);
	ft_strlcpy(subs, s + start, new_len + 1);
	return (subs);
}
