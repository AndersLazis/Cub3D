/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstrassb <tstrassb@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 09:44:04 by tstrassb          #+#    #+#             */
/*   Updated: 2022/12/15 11:49:55 by tstrassb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *bigs, const char *smalls, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (ft_strlen(smalls) == 0)
		return ((char *)bigs);
	while (i < len && bigs[i])
	{
		j = 0;
		while (bigs[i + j] == smalls[j]
			&& bigs[i + j] && smalls[j] && i + j < len)
		j++;
		if (!smalls[j])
			return ((char *)bigs + i);
		else
			i++;
	}
	return (0);
}
