/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:52:10 by mschulme          #+#    #+#             */
/*   Updated: 2023/05/09 12:52:10 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/*
int main(void)
{
    int c = '5';
    printf("%d \n", isdigit(c));
    printf("%d \n", ft_isdigit(c));
}
*/

/*
cc -Wall -Wall -Wextra ft_isdigit.c 
*/
