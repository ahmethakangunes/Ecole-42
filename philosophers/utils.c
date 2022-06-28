/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:46:15 by agunes            #+#    #+#             */
/*   Updated: 2022/06/28 20:00:52 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_list *philo)
{
	takefork(philo);
	get_time(philo);
	printf("%lu %d eating.\n", philo->time_to_start, philo->id);
	usleep(philo->eat * 1000);
	philo->ec++;
	leavefork(philo);
	meal(philo);
	mealcheck(philo);
}

void	waitsleep(t_list *philo)
{
	get_time(philo);
	printf("%lu %d sleeping.\n", philo->time_to_start, philo->id);
	usleep(philo->sleep * 1000);
}

void	think(t_list *philo)
{
	get_time(philo);
	printf("%lu %d thinking.\n", philo->time_to_start, philo->id);
}
