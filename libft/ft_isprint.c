/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:56:10 by mschulme          #+#    #+#             */
/*   Updated: 2023/05/09 12:56:10 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}

/*
int main(void)
{
	int c = 125;
	printf("%d \n", isprint(c));
	printf("%d \n", ft_isprint(c));
}
*/

/*
cc -Wall -Wall -Wextra ft_isprint.c
*/
