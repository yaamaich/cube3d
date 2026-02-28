/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamddah <aamddah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:24:37 by aamddah           #+#    #+#             */
/*   Updated: 2024/11/03 16:14:55 by aamddah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_put_n(char *str, int n, int nl)
{
	int		i;
	long	d;

	i = 0;
	d = n;
	if (d < 0)
	{
		str[0] = '-';
		d *= -1;
		i++;
	}
	str [nl] = '\0';
	nl--;
	while (nl >= i)
	{
		str[nl] = (d % 10) + 48;
		d = d / 10;
		nl--;
	}
}

static int	ft_nbrlen(int n)
{
	int		num;
	long	d;

	num = 1;
	d = n;
	if (d < 0)
		d *= -1;
	while (d / 10 > 0)
	{
		num++;
		d = d / 10;
		if (d / 10 == 0)
		{
			break ;
		}
	}
	return (num);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		nl;

	nl = ft_nbrlen(n);
	if (n < 0)
		nl += 1;
	str = (char *)malloc((nl + 1) * sizeof(char));
	if (!str)
		return (NULL);
	ft_put_n (str, n, nl);
	return (str);
}
