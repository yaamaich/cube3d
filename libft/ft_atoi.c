/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamddah <aamddah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:17:01 by aamddah           #+#    #+#             */
/*   Updated: 2024/10/31 10:28:00 by aamddah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_check(const char *str, long result, unsigned int i, int sign)
{
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((result * 10) + (str[i] - 48) < 0 && sign == -1)
			return (0);
		else if ((result * 10) + (str[i] - 48) < 0)
			return (-1);
		else
		{
			result *= 10;
			result += str[i] - 48;
			i++;
		}
	}
	return (result *= sign);
}

int	ft_atoi(const char *str)
{
	unsigned int	i;
	long			result;
	int				sign;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
	{
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str [i] == '-')
			sign *= -1;
		i++;
	}
	return ((int)ft_check(str, result, i, sign));
}
