/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamddah <aamddah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:28:53 by aamddah           #+#    #+#             */
/*   Updated: 2024/11/05 15:45:18 by aamddah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	n;

	if (!lst)
	{
		return (0);
	}
	n = 0;
	while (lst != NULL)
	{
		lst = (*lst).next;
		n++;
	}
	return (n);
}
