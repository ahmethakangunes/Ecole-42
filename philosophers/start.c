/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:06:24 by agunes            #+#    #+#             */
/*   Updated: 2022/07/19 19:32:53 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*worker(void *arg)
{
	t_list	*philo;

	philo = (t_list *)arg;
	philo->ec = 0;
	philo->dtime = philo->time_to_start + philo->die;
	while (1)
	{
		check_die(philo);
		if (is_finished(philo) == 0)
			break ;
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
	philo->freemutex = openmutex(philo);
	philo->freefork = openfork(philo);
	philo->freesamemutex = samemutex(philo);
	philo->freediecount = diecount(philo);
	while (i < philo->phi)
	{
		pthread_create(&philo[i].thread, NULL, worker, &philo[i]);
		i += 2;
	}
	i = 1;
	usleep(600);
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
