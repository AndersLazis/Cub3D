/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convers_selection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstrassb <tstrassb@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:34:07 by tstrassb          #+#    #+#             */
/*   Updated: 2023/01/02 08:39:26 by tstrassb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convers_c(va_list arg)
{
	char	c;

	c = (char) va_arg(arg, int);
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_convers_s(va_list arg)
{
	char	*c;

	c = va_arg(arg, char *);
	if (!c)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(c, 1);
	return (ft_strlen(c));
}

int	ft_convers_di(va_list arg)
{
	int	i;

	i = va_arg(arg, int);
	ft_putnbr_fd(i, 1);
	return (ft_intlen(i));
}

int	ft_convers_x(va_list arg)
{
	unsigned int	i;

	i = va_arg(arg, int);
	if (i == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	return (ft_convers_hexa(i));
}

int	ft_convers_cx(va_list arg)
{
	unsigned int	i;

	i = va_arg(arg, int);
	if (i == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	return (ft_convers_hexaupper(i));
}
