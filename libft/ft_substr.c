/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:14:05 by aputiev           #+#    #+#             */
/*   Updated: 2022/12/25 23:12:59 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*newstr(size_t len, int start, char const *s)
{
	char	*str;

	if ((size_t)start > ft_strlen (s))
		str = malloc(1);
	else if (len + (size_t)start > ft_strlen (s))
		str = malloc((ft_strlen (s) - start) + 1);
	else
		str = malloc(len + 1);
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s)
		return (NULL);
	if (ft_strlen (s) < len)
		len = ft_strlen(s);
	str = newstr(len, start, s);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}

// int main ()
// {
// 	printf("%s",ft_substr("abcdefghijk" ,3,4));
// }
