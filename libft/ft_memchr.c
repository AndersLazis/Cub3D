/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:11:45 by mschulme          #+#    #+#             */
/*   Updated: 2023/05/09 13:11:45 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*str;

	str = (char *)s;
	while (n--)
	{
		if (*str == (char) c)
			return (str);
		str++;
	}
	return (NULL);
}

/*
int main(void)void	ft_swap(int *a, int *b);
void	ft_quicksort(int arr[], int start, int end, int seed);
int		getSmall(int *arr, int j, int start, int pivot);
int		getBig(int *arr, int i, int end, int pivot);
int		ft_lincongrugene(int seed);
{
	char *test= "hallo Wt";
	printf("%s \n", memchr(test, 'H', 15));
	printf("%s \n", ft_memchr(test, 'H', 15));
}
*/
