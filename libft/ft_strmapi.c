/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 07:37:28 by aputiev           #+#    #+#             */
/*   Updated: 2022/12/25 22:37:07 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*t;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	else if (!f)
		return (ft_strdup(s));
	t = ft_strdup(s);
	if (!t)
		return (NULL);
	while (s[i] != '\0')
	{
		t[i] = (*f)(i, s[i]);
		i++;
	}
	return (t);
}

// char f (unsigned int i, char c)
// {
// 	char res;
// 	i = i;
// 	res = c + 2;
// 	return (res);
// }

// #include <stdio.h>
// int main ()
// {
// 	char const *p = "abcd";
// 	printf("%s",ft_strmapi(p ,f));	
// }
