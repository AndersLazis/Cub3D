/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:46:58 by aputiev           #+#    #+#             */
/*   Updated: 2022/12/25 17:09:04 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset (s, 0, n);
}

// void arr_print(char arr[], int n)
// {
//     int i =0;
//     for (i=0; i<n; i++)
//     {
//         printf("%c", arr[i]);
//     }
// }

// int main()
// {
//     char arr[] = "abcdefgh";
//     ft_bzero(arr,2);
//     arr_print(arr,5);
//     return 0;
// }
