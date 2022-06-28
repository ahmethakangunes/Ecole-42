/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:06:07 by agunes            #+#    #+#             */
/*   Updated: 2022/06/28 20:04:40 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	meal(t_list *philo)
{
	pthread_mutex_lock(philo->lock);
	if (philo->ec == philo->meat)
		philo->eatarray[philo->id - 1] = 1;
	pthread_mutex_unlock(philo->lock);
}

void	mealcheck(t_list *philo)
{
	int	i;
	int	count;

	pthread_mutex_lock(philo->lock);
	i = 0;
	count = 0;
	while (i < philo->phi)
	{
		if (philo->eatarray[i] == 1)
			count++;
		i++;
	}
	if (count == philo->phi)
		exit (1);
	pthread_mutex_unlock(philo->lock);
}

void	get_time(t_list *philo)
{
	static int				ms;
	static int				start;

	pthread_mutex_lock(philo->lock);
	gettimeofday(&philo->tv, NULL);
	ms = (philo->tv.tv_sec * 1000) + (philo->tv.tv_usec / 1000);
	if (start == 0)
		start = ms;
	philo->time_to_start = ms - start;
	pthread_mutex_unlock(philo->lock);
}