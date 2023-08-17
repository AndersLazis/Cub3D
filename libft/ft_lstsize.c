/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:39:18 by mschulme          #+#    #+#             */
/*   Updated: 2023/05/09 13:39:18 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		length;

	if (lst == NULL)
		return (0);
	length = 1;
	while (lst->next != 0)
	{
		lst = lst->next;
		length++;
	}
	return (length);
}
