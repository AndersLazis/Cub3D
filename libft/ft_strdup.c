/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:37:11 by aputiev           #+#    #+#             */
/*   Updated: 2022/12/25 19:59:41 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*str;

	i = 0;
	while (s1[i] != '\0')
		i++;
	str = malloc(i + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
	str[i] = s1[i];
	i++;
	}
	str[i] = '\0';
	return (str);
}

// int main(void)
// {
// 	char *str ="abcdefghijk";
// 	printf("%s",ft_strdup(str));
// 	printf("\n");
// 	printf("%s",strdup(str));
// }
