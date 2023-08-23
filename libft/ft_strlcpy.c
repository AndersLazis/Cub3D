/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 11:56:07 by aputiev           #+#    #+#             */
/*   Updated: 2022/12/25 20:40:52 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	a;

	i = 0;
	a = ft_strlen(src);
	if (!dstsize)
		return (a);
	while (src[i] && i < dstsize - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (a);
}

// int main()
// {
//     char p[]= "abcdefgh";
//     char s[]= "123";
//     printf("%ld",ft_strlcpy(p,s,4));
// 	printf("\n");
// 	printf("%s",p);
// }