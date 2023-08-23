/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:42:27 by aputiev           #+#    #+#             */
/*   Updated: 2022/12/25 23:47:40 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	size_t	i;
	char	*p;

	i = 0;
	p = s;
	while (i < len)
	{
		*p = (char)c;
		i++;
		p++;
	}
	return (s);
}

// void	printArray(char arr[], int n)
// {
//     int i =0;
//     for (i=0; i<n; i++)
//     {
//         printf("%c", arr[i]);
//     }
// }

// int main()
// {
//     char arr[4] = "abcd";    
//     ft_memset(arr,'l', sizeof(arr));
//     printArray(arr,4);
//     printf("\n");
//     char arr1[4] = "abcd";
//     memset(arr1,'l', sizeof(arr1));
//     printArray(arr1,4);
//     return 0;
// }