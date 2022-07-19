/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutexandfork.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 12:23:15 by agunes            #+#    #+#             */
/*   Updated: 2022/07/19 19:32:58 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t	*openmutex(t_list *philo)
{
	int				i;
	pthread_mutex_t	*mutex;

	i = 0;
	mutex = malloc(sizeof(pthread_mutex_t) * philo->phi);
	if (!mutex)
		return (0);
	while (i < philo->phi)
		pthread_mutex_init(&mutex[i++], NULL);
	i = 1;
	while (i < philo->phi)
	{
		philo[i].rmutex = &mutex[i];
		philo[i].lmutex = &mutex[i - 1];
		i++;
	}
	philo[0].rmutex = &mutex[0];
	philo[0].lmutex = &mutex[philo->phi - 1];
	return (mutex);
}

int	*openfork(t_list *philo)
{
	int				i;
	int				*fork;

	i = 0;
	fork = malloc(sizeof(int) * philo->phi);
	if (!fork)
		return (0);
	while (i < philo->phi)
	{	
		fork[i] = 1;
		i++;
	}
	i = 1;
	while (i < philo->phi)
	{
		philo[i].rfork = &fork[i];
		philo[i].lfork = &fork[i - 1];
		i++;
	}
	philo[0].rfork = &fork[0];
	philo[0].lfork = &fork[philo->phi - 1];
	return (fork);
}

pthread_mutex_t	*samemutex(t_list *philo)
{
	int				i;
	pthread_mutex_t	*lock;

	i = 0;
	lock = malloc(sizeof(pthread_mutex_t));
	if (!lock)
		return (0);
	pthread_mutex_init(lock, NULL);
	while (i < philo->phi)
		philo[i++].lock = lock;
	return (lock);
}

int	*diecount(t_list *philo)
{
	int	*diecount;
	int	i;

	diecount = malloc(sizeof(int));
	i = 0;
	if (!diecount)
		return (0);
	*diecount = 1;
	while (i < philo->phi)
		philo[i++].finish = diecount;
	return (diecount);
}
