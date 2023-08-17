/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:34:59 by mschulme          #+#    #+#             */
/*   Updated: 2023/05/09 13:34:59 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*strmod;

	strmod = malloc(ft_strlen(s) + 1);
	if (!strmod)
		return (NULL);
	i = 0;
	while (s[i] != 0)
	{
		strmod[i] = (*f)(i, s[i]);
		i++;
	}
	strmod[i] = 0;
	return (strmod);
}
