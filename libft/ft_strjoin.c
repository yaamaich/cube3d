/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamddah <aamddah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:20:39 by aamddah           #+#    #+#             */
/*   Updated: 2024/11/05 16:35:03 by aamddah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_l;
	size_t	s2_l;
	size_t	total_l;
	char	*s3;

	if (!s1 || !s2)
		return (NULL);
	s1_l = ft_strlen(s1);
	s2_l = ft_strlen(s2);
	total_l = s1_l + s2_l;
	s3 = (char *)malloc((total_l + 1) * sizeof(char));
	if (!s3)
	{
		return (NULL);
	}
	ft_strlcpy(s3, s1, total_l + 1);
	ft_strlcat(s3, s2, total_l + 1);
	return (s3);
}
