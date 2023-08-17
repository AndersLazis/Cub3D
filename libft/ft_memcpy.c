/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:03:09 by mschulme          #+#    #+#             */
/*   Updated: 2023/05/09 13:03:09 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *source, size_t n)
{
	char	*dst;
	char	*src;

	dst = (char *)dest;
	src = (char *)source;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (n--)
		*(dst++) = *(src++);
	return (dest);
}

/*
int main(void)
{
	char dest[] = "NUL";
	char src[] = "NULL";

	printf("%s \n",  memcpy(dest, src, 3));
}
*/
