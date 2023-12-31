/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstrassb <tstrassb@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:36:48 by tstrassb          #+#    #+#             */
/*   Updated: 2022/12/15 11:51:51 by tstrassb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*bsrc;
	char	*bdst;

	if (dst == src)
		return (dst);
	bsrc = (char *)src;
	bdst = (char *)dst;
	i = -1;
	if (src > dst)
	{
		while (len > ++i)
			bdst[i] = bsrc[i];
	}
	else
	{
		while (len)
		{
			bdst[len - 1] = bsrc[len - 1];
			len--;
		}
	}
	return (dst);
}
