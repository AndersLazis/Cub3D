/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 17:28:02 by aputiev           #+#    #+#             */
/*   Updated: 2022/12/26 00:17:03 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	ret;

	i = 0;
	if (dst == NULL)
	{
		ret = ft_strlcpy(dst, src, dstsize - i);
		return (ft_strlen (src));
	}
	while (*dst && i < dstsize)
	{
		++dst;
		++i;
	}
	ret = ft_strlcpy(dst, src, dstsize - i);
	return (ret + i);
}

// int main()
// {
//     char src[] = "123456789";
//     char dest[20]="";  
//     size_t sz;
//     printf("%ld\n",ft_strlcat(dest,src,sizeof(dest)));
//     printf("%s\n",dest);

//     sz = ft_strlcat(dest,src,sizeof(dest));

//     if (sz>=sizeof(dest))
//           printf("Truncation has been detected!\n");
//     return(0);
// }