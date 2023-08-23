/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:40:23 by aputiev           #+#    #+#             */
/*   Updated: 2022/12/25 18:14:49 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*s1_1;
	char	*s2_2;
	size_t	i;

	s1_1 = (char *)s1;
	s2_2 = (char *)s2;
	i = 0;
	while (i < n)
	{
		if (*s1_1 != *s2_2)
			return ((unsigned char)*s1_1 - (unsigned char)*s2_2);
	s1_1++;
	s2_2++;
	i++;
	}
	return (0);
}

// #include <stdio.h>
// int main()
// {
// 	char str1[] = "abcdefgh";
// 	char str2[] = "abcdeggh";
// 	int res = ft_memcmp(str1, str2, 7);
// 	if (res == 0)
// 		printf("none");
// 	else 
// 	{
// 		printf("%d\n", res);
// 	}
// return 0;
// }