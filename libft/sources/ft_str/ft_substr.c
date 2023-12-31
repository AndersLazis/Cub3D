/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstrassb <tstrassb@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 14:40:26 by tstrassb          #+#    #+#             */
/*   Updated: 2023/03/05 09:44:30 by tstrassb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, int start, int len)
{
	char			*str;

	if (!s)
		return (NULL);
	if (start > (int)ft_strlen(s))
		return (ft_strdup(""));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	str = (char *)ft_calloc(sizeof(char), len + 1);
	if (str != 0)
		ft_strlcpy(str, s + start, len + 1);
	return (str);
}
