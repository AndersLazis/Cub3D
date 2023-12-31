/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstrassb <tstrassb@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 10:14:58 by tstrassb          #+#    #+#             */
/*   Updated: 2022/12/20 08:51:51 by tstrassb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int	ft_atoi(const char *str)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!str || !str[i])
		return (-1);
	while (str[i] && str[i] >= 48 && str[i] <= 57)
	{
		j = j * 10 + (str[i++] - 48);
		if (j > 2147483647)
			return (-1);
	}
	if (str[i])
		return (-1);
	return (j);
}
