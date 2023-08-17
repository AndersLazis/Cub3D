/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:56:47 by mschulme          #+#    #+#             */
/*   Updated: 2023/05/09 12:56:47 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	if (!s)
		return (0);
	while (*s++)
		count++;
	return (count);
}

/*
int main(void)
{
	char test[] = "Hallo Welt";
	printf("%zu \n", ft_strlen(test));
}
*/

/*
cc -Wall -Wall -Wextra ft_strlen.c 
*/
