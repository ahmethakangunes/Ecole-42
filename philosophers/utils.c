/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:06:07 by agunes            #+#    #+#             */
/*   Updated: 2022/06/30 14:36:22 by agunes           ###   ########.fr       */
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
