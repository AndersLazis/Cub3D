/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:01:04 by mschulme          #+#    #+#             */
/*   Updated: 2023/05/09 13:01:04 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	while (n--)
		*((char *)str++) = '\0';
}

/*
int main(void)
{
	size_t n = 5;
	char test[] = "HalloWelt123";
	char test1[] = "HalloWelt123";
	ft_bzero(test, n);
	bzero(test1, n);
	printf("%c \n", test[3]);
	printf("%c \n ", test1[3]);
}
*/
