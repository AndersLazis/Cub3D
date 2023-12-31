/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_needed.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstrassb <tstrassb@student.42>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 12:17:55 by tstrassb          #+#    #+#             */
/*   Updated: 2023/02/10 11:37:34 by tstrassb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* size_t	ft_strlen(const char *c)
{
	int	i;

	i = 0;
	if (!c)
		return (0);
	while (c[i])
		i++;
	return (i);
} */

/* int	ft_strchr(char *c, char d)
{
	int	i;

	i = 0;
	if (!c)
		return (0);
	while (c[i])
	{
		if (c[i] == d)
			return (1);
		i++;
	}
	return (0);
} */

int	ft_hexlen(int i)
{
	int	lenght;

	lenght = 0;
	if (i == 0)
		return (1);
	while (i != 0)
	{
		i /= 16;
		lenght++;
	}
	return (lenght);
}

int	ft_intlen(int i)
{
	int	lenght;

	lenght = 0;
	if (i == -2147483648)
		return (11);
	if (i == 0)
		return (1);
	if (i < 0)
	{
		lenght++;
		i = -i;
	}
	while (i != 0)
	{
		i /= 10;
		lenght++;
	}
	return (lenght);
}

int	ft_unsignedintlen(unsigned int i)
{
	int	lenght;

	lenght = 0;
	if (i == 0)
		return (1);
	while (i != 0)
	{
		i /= 10;
		lenght++;
	}
	return (lenght);
}
