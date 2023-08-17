/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:10:33 by mschulme          #+#    #+#             */
/*   Updated: 2023/05/09 13:10:33 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n && (*s1 != 0 || *s2 != 0) && (*s1 == *s2))
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	else
		return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

/*
int main(void)
{
	const char test[] = "test\200";
	const char test1[] = "test\0";
	size_t n = 6;
	printf("%d \n", ft_strncmp(test, test1, n));
	printf("%d \n", strncmp(test, test1, n));
}
*/
