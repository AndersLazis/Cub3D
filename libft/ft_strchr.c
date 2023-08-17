/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:10:05 by mschulme          #+#    #+#             */
/*   Updated: 2023/05/09 13:10:05 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str != '\0')
	{
		if (*str == (char) c)
			return ((char *)str);
		str++;
	}
	if (*str == (char) c)
		return ((char *)str);
	return (NULL);
}

/*
int main(void)
{
	const char *test= "efjldj";
	printf("%s \n", ft_strchr(test, '\0'));
	printf("%s \n", strchr(test, '\0'));
}
*/
