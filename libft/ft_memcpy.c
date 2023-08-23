/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 17:58:27 by aputiev           #+#    #+#             */
/*   Updated: 2022/12/25 18:49:30 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*src_1;
	char	*dest_1;
	size_t	i;

	i = 0;
	src_1 = (char *)src;
	dest_1 = (char *)dst;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		dest_1[i] = src_1[i];
		i++;
	}
	return (dst);
}

// int main()
// {
// char csrc[] = "abcd";
// char cdest[9];
// ft_memcpy(cdest, csrc, strlen(csrc)+1);
// printf("Copied string is %s", cdest);
// int isrc[] = {1,2,3,4};
// int n = sizeof(isrc)/sizeof(isrc[0]);
// int idest[n], i;
// ft_memcpy(idest, isrc, sizeof(isrc));
// printf("\nCopied array is ");
// for (i=0; i<n; i++)
//     printf("%d ", idest[i]);
// return 0;
// }
