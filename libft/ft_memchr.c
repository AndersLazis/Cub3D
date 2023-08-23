/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 11:55:03 by aputiev           #+#    #+#             */
/*   Updated: 2022/12/25 18:47:25 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*s1;
	size_t	i;

	i = 0;
	s1 = (char *)s;
	while (i < n)
	{
		if (*s1 == (char)c)
			return ((void *)s1);
		s1++;
		i++;
	}
	return (NULL);
}

// int main()
// {
// 	char str[] = {'a', 'b', 'c', 'd', 'e'};
// 	char* ptr = ft_memchr(str, 'c', 4);
// 	if (ptr == NULL)
// 		printf("none");
// 	else 
// 		printf("%c\n", ptr[0]);
// return 0;
// }