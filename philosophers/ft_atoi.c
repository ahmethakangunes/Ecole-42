/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 11:54:09 by agunes            #+#    #+#             */
/*   Updated: 2022/06/20 13:04:01 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *s1)
{
	int	i;
	int	sayi;
	int	isaret;

	i = 0;
	sayi = 0;
	isaret = 1;
	while (s1[i] <= 32)
		i++;
	if (s1[i] == '-' && s1[i] == '+')
	{
		if (s1[i] == '-')
			isaret *= -1;
		i++;
	}
	while (s1[i] >= '0' && s1[i] <= '9')
	{
		sayi = (sayi * 10) + (s1[i] - 48);
		i++;
	}
	return (sayi * isaret);
}
