/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:41:10 by mschulme          #+#    #+#             */
/*   Updated: 2023/05/09 12:41:10 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

/*
int main(void)
{
	int c = 400;
	printf("%d \n", isalpha(c));
	printf("%d \n", ft_isalpha(c));
}
*/

/*
cc -Wall -Wall -Wextra ft_isalpha.c
*/
