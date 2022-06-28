/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:32:10 by agunes            #+#    #+#             */
/*   Updated: 2022/02/23 13:29:22 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointer(unsigned long long a, int *len)
{
	if (a < 16)
	{
		if (a < 10)
		{
			*len += ft_putchar_fd(a + 48);
		}
		else
			*len += ft_putchar_fd(a + 87);
	}
	else
	{
		ft_pointer(a / 16, len);
		ft_pointer(a % 16, len);
	}
	return (*len);
}
