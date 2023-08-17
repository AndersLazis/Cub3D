/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:57:19 by mschulme          #+#    #+#             */
/*   Updated: 2023/05/09 12:57:19 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	char	*ptr;

	ptr = (char *)str;
	while (n--)
		*ptr++ = c;
	return (str);
}

/*
int main(void)
{
	char test[250];
	int  n = 5;

	ft_memset(test, 100, n);
	n = 0;
	while(n < 5)
	{
		printf("%d", test[n]);
		n = n + 1;
	}
	printf("\n");
	ft_memset(test, 'c', 50);
	n = 10;
	while(n <= 50)
	{
		printf("%c", test[n]);
		n = n + 1;
	}
}
*/

/*
cc -Wall -Wall -Wextra ft_memset.c
*/
