/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:33:00 by agunes            #+#    #+#             */
/*   Updated: 2022/02/23 13:52:10 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned(unsigned int n, int *len)
{
	if (n >= 0 && n <= 9)
		*len += ft_putchar_fd(n + 48);
	if (n > 9)
	{
		ft_unsigned(n / 10, len);
		ft_unsigned(n % 10, len);
	}
	return (*len);
}
