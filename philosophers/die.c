/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 13:32:12 by agunes            #+#    #+#             */
/*   Updated: 2022/07/25 14:13:10 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	check_die(t_list *philo)
{
	get_time(philo);
	usleep(200);
	if (*philo->finish == 1)
	{
		if (philo->time_to_start >= philo->dtime)
			go_and_kill(philo);
	}
}

void	go_and_kill(t_list *philo)
{
	get_time(philo);
	pthread_mutex_lock(philo->lock);
	if (*philo->finish == 1)
	{
		*philo->finish = 0;
		printf("%lu %d has died\n", philo->time_to_start, philo->id);
	}
	pthread_mutex_unlock(philo->lock);
}

int	is_finished(t_list *philo)
{
	int	result;

	pthread_mutex_lock(philo->lock);
	result = *philo->finish;
	pthread_mutex_unlock(philo->lock);
	return (result);
}
