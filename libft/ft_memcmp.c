/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:12:21 by mschulme          #+#    #+#             */
/*   Updated: 2023/05/09 13:12:21 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr;
	unsigned char	*ptr1;

	ptr = (unsigned char *)s1;
	ptr1 = (unsigned char *)s2;
	while (n && (*ptr == *ptr1))
	{
		ptr++;
		ptr1++;
		n--;
	}
	if (n == 0)
		return (0);
	else
		return (*ptr - *ptr1);
}

/*
int main(void)
{
	char *test = "Hal";
	char *test1 = "Hal1";
	printf("%d \n", ft_memcmp(test,test1,40));

	printf("%d \n", memcmp(test,test1,40));
}
*/
