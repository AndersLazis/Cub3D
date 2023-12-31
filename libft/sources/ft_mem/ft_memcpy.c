/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstrassb <tstrassb@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 10:59:40 by tstrassb          #+#    #+#             */
/*   Updated: 2022/12/15 11:53:17 by tstrassb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dest;
	char	*asrc;

	dest = (char *)dst;
	asrc = (char *)src;
	if (src == dst)
		return (dst);
	i = 0;
	while (i < n)
	{
		dest[i] = asrc[i];
		i++;
	}
	return (dst);
}
