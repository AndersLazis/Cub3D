/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstrassb <tstrassb@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:14:45 by tstrassb          #+#    #+#             */
/*   Updated: 2022/12/28 11:15:16 by tstrassb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_lstapply(t_list *l, t_list *s,
	void *(*f)(void *), void (*d)(void *))
{
	if (l)
	{
		s = ft_lstnew(f(l->content));
		if (!s)
		{
			ft_lstdelone(s, d);
			return (0x0);
		}
		s->next = ft_lstapply(l->next, s->next, f, d);
	}
	return (s);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start;

	start = 0x0;
	start = ft_lstapply(lst, start, f, del);
	return (start);
}
