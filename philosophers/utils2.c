/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:46:15 by agunes            #+#    #+#             */
/*   Updated: 2022/07/01 13:39:14 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_list *philo)
{
	takefork(philo);
	get_time(philo);
	printf("%lu %d eating.\n", philo->time_to_start, philo->id);
	ft_usleep(philo, philo->eat);
	philo->ec++;
	leavefork(philo);
	meal(philo);
	mealcheck(philo);
}

void	waitsleep(t_list *philo)
{
	get_time(philo);
	printf("%lu %d sleeping.\n", philo->time_to_start, philo->id);
	ft_usleep(philo, philo->sleep);
}

void	think(t_list *philo)
{
	get_time(philo);
	printf("%lu %d thinking.\n", philo->time_to_start, philo->id);
}

void	ft_usleep(t_list *philo, unsigned long ms)
{
	unsigned long	time;

	get_time(philo);
	time = philo->time_to_start;
	while (philo->time_to_start < time + ms)
		get_time(philo);
}
