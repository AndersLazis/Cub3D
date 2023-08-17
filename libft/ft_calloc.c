/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:27:54 by mschulme          #+#    #+#             */
/*   Updated: 2023/05/09 13:27:54 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nb, size_t size)
{
	void	*ptr;

	ptr = malloc(nb * size);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, nb * size);
	return (ptr);
}

/*
int main(void)
{
	ft_calloc(100,4);
}
*/
