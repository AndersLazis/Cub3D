/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:55:42 by mschulme          #+#    #+#             */
/*   Updated: 2023/06/05 23:23:13 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*helper;

	helper = *lst;
	if (!lst || !del)
		return ;
	while (helper)
	{
		tmp = helper->next;
		ft_lstdelone(helper, del);
		helper = tmp;
	}
	*lst = NULL;
}
