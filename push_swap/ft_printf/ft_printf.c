/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:31:56 by agunes            #+#    #+#             */
/*   Updated: 2022/02/23 14:44:12 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checker(char k, va_list *args)
{
	int	len;

	len = 0;
	if (k == 'c')
		len += ft_putchar_fd(va_arg(*args, int));
	else if (k == 'd' || k == 'i')
		ft_putnbr_fd(va_arg(*args, int), &len);
	else if (k == 's')
		len += ft_putstr_fd(va_arg(*args, char *));
	else if (k == '%')
		len += write(1, "%", 1);
	else if (k == 'p')
	{
		len += write(1, "0x", 2);
		ft_pointer(va_arg(*args, unsigned long long), &len);
	}
	else if (k == 'u')
		ft_unsigned(va_arg(*args, unsigned int), &len);
	else if (k == 'x')
		ft_lowerx(va_arg(*args, unsigned int), &len);
	else if (k == 'X')
		ft_upperx(va_arg(*args, unsigned int), &len);
	return (len);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		len;

	va_start(args, s);
	len = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			len += ft_checker(s[i], &args);
		}
		else
		{
			len += ft_putchar_fd(s[i]);
		}
	i++;
	}
	va_end(args);
	return (len);
}

/* int main()
{
	int a;
	int *b;

	a = 5123;
	b = &a;
	ft_printf("c = %c\n", *b);
	ft_printf("%d\n", *b);
	ft_printf("%i\n", *b);
	ft_printf("%u\n", *b);
	ft_printf("%x\n", *b);
	ft_printf("%X\n", *b);
	ft_printf("%p\n", *b);
	ft_printf("%s\n", *b);
}   */