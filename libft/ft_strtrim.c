/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschulme <mschulme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 13:33:07 by mschulme          #+#    #+#             */
/*   Updated: 2023/05/09 13:33:07 by mschulme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	maximum(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

static bool	foundinstring(char c, char const *set)
{
	unsigned int	i;

	i = 0;
	while (i < ft_strlen(set))
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		i;
	int		min;
	int		max;

	i = 0;
	min = 0;
	max = ft_strlen(s1);
	if (*s1 == 0)
		return (ft_calloc(1, 1));
	while (foundinstring(s1[min], set) == 1)
		min++;
	while (foundinstring(s1[max - 1], set) == 1 && max >= min)
		max--;
	str = malloc(maximum((max - min + 1), 1));
	if (!str)
		return (NULL);
	while (min + i < max)
	{
		str[i] = s1[min + i];
		i++;
	}
	str[i] = 0;
	return (str);
}

/*
int main(void)
{
	char s1[] = "";
	char set[] = "";
	printf("%s:",ft_strtrim(s1,set));
	//printf("%d", ft_strlen(ft_strtrim(s1,set)));
}
*/
