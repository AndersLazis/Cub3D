/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:25:43 by mschulme          #+#    #+#             */
/*   Updated: 2023/05/09 13:25:43 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *pat, size_t len)
{
	size_t	i;
	int		length;

	if (*pat == '\0')
		return ((char *)str);
	i = 0;
	length = ft_strlen(pat);
	while (str[i] != '\0' && (i + length) <= len)
	{
		if (ft_strncmp((str + i), pat, length) == 0)
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}

/*
int main()
{
	char str[] = "see F your F return F now F";
		printf("Test1: search pattern %s\n", ft_strnstr(str, "F", strlen(str)));
		
	return 0;
}
*/
