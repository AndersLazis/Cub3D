/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:05:02 by mschulme          #+#    #+#             */
/*   Updated: 2023/05/09 14:05:02 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen(s);
	if (s[len] == '\0' && (char) c == '\0')
		return ((char *)s + len);
	while (len--)
	{
		if (s[len] == (char) c)
			return ((char *)s + len);
	}
	return (NULL);
}

/*
int main(void)
{
	const char *test= "efjldjdfZdf";
	printf("%s: \n", ft_strrchr(test, '\0'));
	printf("%s: \n", strrchr(test, '\0'));
}
*/
