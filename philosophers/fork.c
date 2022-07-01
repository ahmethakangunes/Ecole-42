/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:44:56 by agunes            #+#    #+#             */
/*   Updated: 2022/07/01 20:54:25 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	takefork(t_list *philo)
{
	while (1)
	{	
		check_die(philo);
		if (is_finished(philo) == 0)
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

void	check_die(t_list *philo)
{
	get_time(philo);
	if (*philo->finish == 1)
	{
		if (philo->time_to_start >= philo->dtime)
			go_and_kill(philo);
	}
}

void go_and_kill(t_list *philo)
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

int is_finished(t_list *philo)
{
	int result;
	pthread_mutex_lock(philo->lock);
	result = *philo->finish;
	pthread_mutex_unlock(philo->lock);
	return (result);
}
