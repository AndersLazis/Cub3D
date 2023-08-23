/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:53:23 by aputiev           #+#    #+#             */
/*   Updated: 2022/12/25 19:53:24 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (s[0] == '\0' && c == '\0')
		return ((char *)s);
	if (!*s)
		return (0);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
	{
		return ((char *)s);
	}
	return (NULL);
}

// int main()
// {
// 	printf("%s",ft_strchr("abcdefgh", 'c'));
// 	printf("\n");
// 	printf("%s\n",strchr("abcdefgh", 'c'));
// }
