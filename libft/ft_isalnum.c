/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 10:38:50 by aputiev           #+#    #+#             */
/*   Updated: 2022/12/25 23:49:22 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c > 96 && c < 123) || (c > 64 && c < 91))
		return (1);
	else if (c > 47 && c < 58)
		return (1);
	else
		return (0);
}

// int main()
// {
// 	 printf("%d",ft_isalnum('^'));
// }
