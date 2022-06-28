/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_upperx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:33:06 by agunes            #+#    #+#             */
/*   Updated: 2022/02/23 13:30:10 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_upperx(unsigned int a, int *len)
{
	if (a < 16)
	{
		if (a < 10)
		{
			*len += ft_putchar_fd(a + 48);
		}
		else
			*len += ft_putchar_fd(a + 55);
	}
	else
	{
		ft_upperx(a / 16, len);
		ft_upperx(a % 16, len);
	}
	return (*len);
}
