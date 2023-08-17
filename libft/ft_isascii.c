/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:53:56 by mschulme          #+#    #+#             */
/*   Updated: 2023/05/09 12:53:56 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}

/*
int main(void)
{
	int c = 440;
	printf("%d \n", isascii(c));
	printf("%d \n", ft_isascii(c));
}
*/

/*
cc -Wall -Wall -Wextra ft_isascii.c
*/
