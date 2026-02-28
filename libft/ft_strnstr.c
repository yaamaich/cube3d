/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamddah <aamddah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:16:09 by aamddah           #+#    #+#             */
/*   Updated: 2024/11/08 15:54:21 by aamddah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	if (!haystack && len == 0)
		return (NULL);
	if (*needle == '\0' || haystack == needle)
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		while (haystack[i + k] == needle[k] && k + i < len)
		{
			k++;
			if (needle[k] == '\0')
				return ((char *)&haystack[i]);
		}
		k = 0;
		i++;
	}
	return (NULL);
}
