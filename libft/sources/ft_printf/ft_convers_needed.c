/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convers_needed.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstrassb <tstrassb@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 12:54:37 by tstrassb          #+#    #+#             */
/*   Updated: 2023/01/02 10:26:10 by tstrassb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convers_hexa(size_t n)
{
	char		temp;
	static int	i;

	i = 0;
	if (n != 0)
	{
		ft_convers_hexa(n / 16);
		if (n % 16 < 10)
			temp = n % 16 + 48;
		else
			temp = n % 16 - 10 + 'a';
		write (1, &temp, 1);
		i++;
	}
	return (i);
}

int	ft_convers_hexaupper(unsigned int n)
{
	char		temp;
	static int	i;

	i = 0;
	if (n != 0)
	{
		ft_convers_hexaupper(n / 16);
		if (n % 16 < 10)
			temp = n % 16 + 48;
		else
			temp = n % 16 - 10 + 'a' - 32;
		write (1, &temp, 1);
		i++;
	}
	return (i);
}

int	ft_convers_voidp(va_list arg)
{
	unsigned long long	i;
	int					j;

	j = 0;
	i = va_arg(arg, unsigned long long);
	if (i == 0)
	{
		ft_putstr_fd("0x0", 1);
		return (3);
	}
	ft_putstr_fd("0x", 1);
	j += 2;
	j += ft_convers_hexa(i);
	return (j);
}

int	ft_convers_u(va_list arg)
{
	unsigned int	i;

	i = va_arg(arg, unsigned int);
	ft_unsignedputnbr_fd(i, 1);
	return (ft_unsignedintlen(i));
}
