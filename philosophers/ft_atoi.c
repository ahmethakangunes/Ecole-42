/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 11:54:09 by agunes            #+#    #+#             */
/*   Updated: 2022/07/02 14:34:46 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	int			i;
	long int	sayi;
	int			isaret;

	i = 0;
	sayi = 0;
	isaret = 1;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		sayi = (sayi * 10) + str[i] - '0';
		i++;
	}
	return (sayi * isaret);
}
