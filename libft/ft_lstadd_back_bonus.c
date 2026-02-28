/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamddah <aamddah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:58:37 by aamddah           #+#    #+#             */
/*   Updated: 2024/11/05 15:33:07 by aamddah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *neew)
{
	t_list	*p;

	p = neew;
	if (!lst || !neew)
		return ;
	if (*lst)
		ft_lstlast(*lst)->next = p;
	else
		*lst = p;
}
