/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:05:09 by mschulme          #+#    #+#             */
/*   Updated: 2023/05/09 13:05:09 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*strdest;

	strdest = (char *) dest;
	if (!dest && !src)
		return (NULL);
	if (strdest > (char *)src)
		while (n--)
			strdest[n] = ((char *)src)[n];
	else
		while (n--)
			*strdest++ = *((char *)src++);
	return (dest);
}

/*
int main(void)
{
	char str[] = "lorem ipsum dolor sit amet";
	char dest [] = "test";

	printf("%s: \n", memmove(dest, str, 8));

	printf("%s: \n", ft_memmove(dest, str, 8));
	char str1[] = "lorem ipsum dolor sit amet";
	char *dest1;
	dest1 = str1 + 1;
	printf("%s: \n", dest1);
	printf("%s: \n", memmove(str1, dest1, 8));
}
*/
