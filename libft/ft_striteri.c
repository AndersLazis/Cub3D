/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aputiev <aputiev@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 08:15:54 by aputiev           #+#    #+#             */
/*   Updated: 2022/12/25 20:14:34 by aputiev          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void f (unsigned int a, char* b)
// {
//     printf("%d, %c", a, *b);
// 	printf("\n");
// }

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (s && f)
	{
		while (s[i] != '\0')
		{
			f(i, &s[i]);
			i++;
		}
	}
}

// int main()
// {
// 	char *s ="abcd";
// 	ft_striteri(s,f);
// }