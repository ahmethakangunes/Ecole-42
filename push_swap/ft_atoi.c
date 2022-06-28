/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:12:36 by agunes            #+#    #+#             */
/*   Updated: 2022/06/01 12:40:04 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *str, t_list *ps)
{
	int			i;
	long int	number;
	int			sign;

	i = 0;
	number = 0;
	sign = 1;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		sign -= (str[i++] == '-') * 2;
		if (str[i] == '+' || str[i] == '-' || str[i] == '\0')
			ft_exit(ps, 2);
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = (number * 10) + str[i++] - '0';
		if (number * sign > 2147483647 || \
			number * sign < -2147483648)
			ft_exit(ps, 2);
	}
	if (str[i] != '\0' && !(str[i] >= '0' && str[i] <= '9'))
		ft_exit(ps, 2);
	return (number * sign);
}
