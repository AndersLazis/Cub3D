/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstrassb <tstrassb@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 10:58:31 by tstrassb          #+#    #+#             */
/*   Updated: 2022/12/18 10:58:31 by tstrassb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*rest;
	size_t	i;

	if (!s)
		return (NULL);
	rest = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!rest)
		return (NULL);
	i = 0;
	while (s[i])
	{
		rest[i] = f(i, s[i]);
		i++;
	}
	rest[i] = '\0';
	return (rest);
}
