/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choose_convers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstrassb <tstrassb@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 11:57:07 by tstrassb          #+#    #+#             */
/*   Updated: 2022/12/30 14:52:24 by tstrassb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_choose_convers(va_list arg, char c)
{
	if (c == 'c')
		return (ft_convers_c(arg));
	else if (c == 's')
		return (ft_convers_s(arg));
	else if (c == 'd' || c == 'i')
		return (ft_convers_di(arg));
	else if (c == 'x')
		return (ft_convers_x(arg));
	else if (c == 'X')
		return (ft_convers_cx(arg));
	else if (c == 'p')
		return (ft_convers_voidp(arg));
	else if (c == 'u')
		return (ft_convers_u(arg));
	else
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	return (0);
}
