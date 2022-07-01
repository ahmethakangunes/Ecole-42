/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:06:24 by agunes            #+#    #+#             */
/*   Updated: 2022/07/01 17:22:04 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*worker(void *arg)
{
	t_list	*philo;

	philo = (t_list *)arg;
	philo->ec = 0;
	while (1)
	{
		eat(philo);
		if (philo->ec == philo->meat)
			break ;
		waitsleep(philo);
		think(philo);
	}
	return (NULL);
}

int	start(t_list *philo)
{
	int				i;

	i = 0;
	if (!openmutex(philo) || !openfork(philo) || !samemutex(philo) || \
	!eatarray(philo) || !diearray(philo))
		return (0);
	while (i < philo->phi)
	{
		pthread_create(&philo[i].thread, NULL, worker, &philo[i]);
		i += 2;
	}
	i = 1;
	while (i < philo->phi)
	{
		pthread_create(&philo[i].thread, NULL, worker, &philo[i]);
		i += 2;
	}
	i = 0;
	while (i < philo->phi)
		pthread_join(philo[i++].thread, NULL);
	return (1);
}
