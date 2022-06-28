/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 17:32:29 by agunes            #+#    #+#             */
/*   Updated: 2022/02/23 13:32:05 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int	ft_printf(const char *s, ...);
int	ft_checker(char k, va_list *args);
int	ft_putchar_fd(char c);
int	ft_putnbr_fd(int n, int *s);
int	ft_putstr_fd(char *s);
int	ft_unsigned(unsigned int n, int *s);
int	ft_upperx(unsigned int a, int *s);
int	ft_pointer(unsigned long long a, int *s);
int	ft_lowerx(unsigned int a, int *s);
int	ft_point(unsigned long long a, int *s);

#endif