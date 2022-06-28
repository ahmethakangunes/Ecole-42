/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:28:37 by agunes            #+#    #+#             */
/*   Updated: 2022/05/05 13:28:39 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>

int	ft_putchar_fd(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr_fd(int n, int *s)
{
	if (n == -2147483648)
	{
		*s += ft_putchar_fd('-');
		*s += ft_putchar_fd('2');
		n = 147483648;
	}
	if (n < 0)
	{
		*s += ft_putchar_fd('-');
		n *= -1;
	}
	if (n >= 0 && n <= 9)
		*s += ft_putchar_fd(n + 48);
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, s);
		ft_putnbr_fd(n % 10, s);
	}
	return (*s);
}

int	ft_putstr_fd(char *s)
{
	int	i;

	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (s[i] != 0)
	{
		ft_putchar_fd(s[i]);
		i++;
	}
	return (i);
}

int	ft_checker(char k, va_list *args)
{
	int	result;

	result = 0;
	if (k == 'c')
		result += ft_putchar_fd(va_arg(*args, int));
	if (k == 'd' || k == 'i')
		ft_putnbr_fd(va_arg(*args, int), &result);
	if (k == 's')
		result += ft_putstr_fd(va_arg(*args, char *));
	return (result);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		i;
	int		result;

	va_start(args, s);
	result = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;
			result += ft_checker(s[i], &args);
		}
		else
		{
			result += write(1, &s[i], 1);
		}
	i++;
	}
	va_end(args);
	return (result);
}

/*   int main()
 {
	 printf("%X\n", -16);
	 ft_printf("%X", -16);
 }  */