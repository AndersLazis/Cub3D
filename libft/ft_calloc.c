/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:03:11 by aputiev           #+#    #+#             */
/*   Updated: 2022/12/25 17:32:28 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdint.h>

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;

	if (count == SIZE_MAX && size == SIZE_MAX)
		return (NULL);
	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < count * size)
	{
		ptr[i] = 0;
		i++;
	}
	return ((void *)ptr);
}

// int main()
// {
//     char *res;
//     res = (char *)ft_calloc(2,4);
//     int i = 0;
//     while (i < 2*4-1)
//         {res[i] = 'a';
//         i++;}
//     printf("%s\n", res);
// }