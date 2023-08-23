/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:13:07 by aputiev           #+#    #+#             */
/*   Updated: 2022/12/25 23:30:55 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	f_check(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1)
		return (ft_strdup(""));
	if (!set)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1);
	while (f_check(s1[start], set))
		start++;
	if (start == end)
		return (ft_strdup(""));
	while (f_check(s1[end - 1], set))
		end--;
	return (ft_substr(s1, start, end - start));
}

// int main() 
// {
// char str1[] = "abcdefghijkab"; 
// char set[] = "ab";   
// char* res;
// res = ft_strtrim(str1, set);
// printf("%s", res);
//   return 0;
// }