/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doublelst_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstrassb <tstrassb@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 17:15:32 by aputiev           #+#    #+#             */
/*   Updated: 2023/08/29 16:19:41 by tstrassb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/cub3d_bonus.h"

t_list	*ft_lstnew(void *cont)
{
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	if (!lst)
		return (0);
	lst->content = cont;
	lst->next = NULL;
	return (lst);
}

t_doublell	*doublelst_new(void *cont)
{
	t_doublell	*lst;

	lst = malloc(sizeof(t_doublell));
	if (!lst)
		return (0);
	lst->next = lst;
	lst->prev = lst;
	lst->content = cont;
	return (lst);
}

void	doublelst_addback(t_doublell **lst, t_doublell *new)
{
	t_doublell	*temp;

	if (!(*lst))
		*lst = new;
	else
	{
		temp = (*lst)->prev;
		temp->next = new;
		new->prev = temp;
		new->next = (*lst);
		(*lst)->prev = new;
	}
}

void	doublelst_free(t_doublell **list)
{
	t_doublell	*temp;
	t_doublell	*first;

	if (*list == 0)
		return ;
	temp = (*list)->next;
	(*list)->next = 0;
	while (temp)
	{
		free(temp->content);
		first = temp;
		temp = temp->next;
		free(first);
	}
}
