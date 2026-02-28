/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamddah <aamddah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:28:29 by aamddah           #+#    #+#             */
/*   Updated: 2024/11/05 19:18:12 by aamddah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!lst || !*lst || !del)
	{
		return ;
	}
	tmp = *lst;
	while (tmp)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp; 
	}
}
