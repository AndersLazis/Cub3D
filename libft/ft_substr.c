/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:30:38 by mschulme          #+#    #+#             */
/*   Updated: 2023/05/09 13:30:38 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	if (start >= ft_strlen(s))
	{
		str = ft_calloc(1, 1);
		if (!str)
			return (NULL);
		return (str);
	}
	if (ft_strlen(s) < start + len)
		len = ft_strlen(s) - start;
	str = ft_calloc(len + 1, 1);
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	return (str);
}

/*
int main(void)
{
	char test[] = "lorem ipusm";
	printf("%s", ft_substr(test, 0, 10));
}
*/
