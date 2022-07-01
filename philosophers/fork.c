/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:44:56 by agunes            #+#    #+#             */
/*   Updated: 2022/07/01 20:23:54 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	takefork(t_list *philo)
{
	while (1)
	{	
		check_die(philo);
		if (!is_finished(philo))
			break ;
		pthread_mutex_lock(philo->rmutex);
		if (*philo->rfork == 1)
		{
			get_time(philo);
			printf("%lu %d has taken a fork\n", philo->time_to_start, philo->id);
			*philo->rfork = 0;
			philo->rhand = 1;
		}
		pthread_mutex_unlock(philo->rmutex);
		pthread_mutex_lock(philo->lmutex);
		if (*philo->lfork == 1)
		{
			get_time(philo);
			printf("%lu %d has taken a fork\n", philo->time_to_start, philo->id);
			*philo->lfork = 0;
			philo->lhand = 1;
		}
		pthread_mutex_unlock(philo->lmutex);
		if (philo->rhand == 1 && philo->lhand == 1)
			break ;
		
	}
}

void	leavefork(t_list *philo)
{
	pthread_mutex_lock(philo->rmutex);
	if (*philo->rfork == 0)
	{
		*philo->rfork = 1;
		philo->rhand = 0;
	}
	pthread_mutex_unlock(philo->rmutex);
	pthread_mutex_lock(philo->lmutex);
	if (*philo->lfork == 0)
	{
		*philo->lfork = 1;
		philo->lhand = 0;
	}
	pthread_mutex_unlock(philo->lmutex);
}
