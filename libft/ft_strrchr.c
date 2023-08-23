/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 18:05:04 by aputiev           #+#    #+#             */
/*   Updated: 2022/12/25 23:03:40 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*s1;

	s1 = s;
	if (s[0] == '\0' && c == 0)
		return ((char *)s);
	if (!*s)
		return (NULL);
	while (*s)
		s++;
	while (s >= s1)
	{
		if (*s == (char)c)
			return ((char *)s);
		s--;
	}
	return (NULL);
}

// int main()
// {
// 	printf("%s",ft_strrchr("abcdefgh", 'f'));
// 	printf("\n");
// 	printf("%s\n",strrchr("abcdefgh", 'f'));
// }
