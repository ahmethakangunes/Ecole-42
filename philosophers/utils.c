/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 15:46:15 by agunes            #+#    #+#             */
/*   Updated: 2022/07/01 16:01:28 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_list *philo)
{
	takefork(philo);
	get_time(philo);
	printf("%lu %d eating.\n", philo->time_to_start, philo->id);
	ft_usleep(philo, philo->eat);
	philo->dtime = philo->time_to_start + philo->die;
	if (philo->time_to_start >= philo->dtime)
		philo->diearray[0] = 1;
	philo->ec++;
	leavefork(philo);
}

int	die(t_list *philo)
{
	if (philo->diearray[0] == 0)
		return (1);
	return (0);
}

void	waitsleep(t_list *philo)
{
	get_time(philo);
	if (philo->time_to_start >= philo->dtime)
		philo->diearray[0] = 1;
	printf("%lu %d sleeping.\n", philo->time_to_start, philo->id);
	ft_usleep(philo, philo->sleep);
}

void	think(t_list *philo)
{
	get_time(philo);
	if (philo->time_to_start >= philo->dtime)
		philo->diearray[0] = 1;
	printf("%lu %d thinking.\n", philo->time_to_start, philo->id);
}

void	ft_usleep(t_list *philo, unsigned long ms)
{
	unsigned long	time;

	get_time(philo);
	time = philo->time_to_start;
	while (philo->time_to_start < time + ms)
		get_time(philo);
}
