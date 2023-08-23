/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:58:36 by aputiev           #+#    #+#             */
/*   Updated: 2022/12/25 19:12:36 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*d;
	char	*s;

	d = (char *)dst;
	s = (char *)src;
	if (dst == src)
		return (dst);
	if (s < d)
	{
		while (len--)
			*(d + len) = *(s + len);
		return (dst);
	}
	while (len--)
		*d++ = *s++;
	return (dst);
}

// #include <stdio.h>
// int main()
// {
//     char msrc[] = "abcde";
//     char mdest[10]; 
//     ft_memmove(mdest, msrc, strlen(msrc)+1);
//    printf("Copied string is %s", mdest);
//     //  ft_memmove((msrc+2), msrc, 4);
//     //  printf("Copied string is %s", msrc+2);
// return 0;
// }
