/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 12:46:46 by mschulme          #+#    #+#             */
/*   Updated: 2023/05/09 12:46:46 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

/*
int main(void)
{
    int c = '5';
    printf("%d \n", isalnum(c));
    printf("%d \n", ft_isalnum(c));
}
*/

/*
cc -Wall -Wall -Wextra ft_isalnum.c
*/
