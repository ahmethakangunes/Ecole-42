/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:44:56 by agunes            #+#    #+#             */
/*   Updated: 2022/06/28 15:45:07 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	takefork(t_list *philo)
{
	pthread_mutex_lock(philo->rmutex);
	pthread_mutex_lock(philo->lmutex);
	get_time(philo);
	printf("%lu %d take a fork\n", philo->time_to_start, philo->id);
	printf("%lu %d take a fork\n", philo->time_to_start, philo->id);
}

void	leavefork(t_list *philo)
{
	pthread_mutex_unlock(philo->rmutex);
	pthread_mutex_unlock(philo->lmutex);
}
