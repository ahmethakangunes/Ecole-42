/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:46:15 by agunes            #+#    #+#             */
/*   Updated: 2022/07/01 20:22:57 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_list *philo)
{
	takefork(philo);
	get_time(philo);
	if (is_finished(philo))
		printf("%lu %d eating.\n", philo->time_to_start, philo->id);
	ft_usleep(philo, philo->eat);
	philo->ec++;
	leavefork(philo);
}

void	waitsleep(t_list *philo)
{
	get_time(philo);
	if (is_finished(philo))
		printf("%lu %d sleeping.\n", philo->time_to_start, philo->id);
	ft_usleep(philo, philo->sleep);
}

void	think(t_list *philo)
{
	get_time(philo);
	if (is_finished(philo))
		printf("%lu %d thinking.\n", philo->time_to_start, philo->id);
}

void	ft_usleep(t_list *philo, unsigned long ms)
{
	unsigned long	time;

	get_time(philo);
	time = philo->time_to_start;
	while (philo->time_to_start < time + ms)
	{
		get_time(philo);
		check_die(philo);
	}		
}

void	check_die(t_list *philo)
{
	if (*philo->finish == 1)
	{
		if (philo->time_to_start >= philo->dtime)
		{
			go_and_kill(philo);
			printf("%lu %d has died\n", philo->time_to_start, philo->id);
		}	
	}
}

void go_and_kill(t_list *philo)
{
	pthread_mutex_lock(philo->lock);
	if (*philo->finish == 1)
		*philo->finish = 0;
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

