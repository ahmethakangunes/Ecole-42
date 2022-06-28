/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:32:47 by agunes            #+#    #+#             */
/*   Updated: 2022/02/23 13:29:41 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(int n, int *len)
{
	if (n == -2147483648)
	{
		*len += ft_putchar_fd('-');
		*len += ft_putchar_fd('2');
		n = 147483648;
	}
	if (n < 0)
	{
		*len += ft_putchar_fd('-');
		n *= -1;
	}
	if (n >= 0 && n <= 9)
		*len += ft_putchar_fd(n + 48);
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, len);
		ft_putnbr_fd(n % 10, len);
	}
	return (*len);
}
