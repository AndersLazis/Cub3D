/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:07:57 by mschulme          #+#    #+#             */
/*   Updated: 2023/05/09 13:07:57 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*d;
	size_t	catcounter;
	size_t	dstlen;

	d = dst;
	catcounter = size;
	while (catcounter-- != 0 && *d != '\0')
		d++;
	dstlen = d - dst;
	catcounter = size - dstlen;
	if (catcounter == 0)
		return (dstlen + ft_strlen(src));
	while (*src != '\0')
	{
		if (catcounter != 1)
		{
			*d++ = *src;
			catcounter--;
		}
		dstlen++;
		src++;
	}
	*d = '\0';
	return (dstlen);
}

/*
int main(void)
{
	char dest[25];

	dest[0] = 'A';
	dest[1] = 'B';
	dest[2] = 0; 
	ft_strlcat(dest, "lorem ipsum dolor sit amet", 4);
	printf("%s", dest);

}
*/
