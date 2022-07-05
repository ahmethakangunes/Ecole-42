/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:55:47 by agunes            #+#    #+#             */
/*   Updated: 2022/07/05 16:28:06 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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

int	setup(int argc, char **argv)
{
	t_list		*philo;
	int			i;

	i = 0;
	if (argc == 5 || argc == 6)
	{
		philo = malloc(sizeof(t_list) * ft_atoi(argv[1]));
		if (!philo)
			return (0);
		while (i < ft_atoi(argv[1]))
		{
			if (argc == 6)
				philo[i].meat = ft_atoi(argv[5]);
			philo[i].phi = ft_atoi(argv[1]);
			philo[i].id = i + 1;
			philo[i].die = ft_atoi(argv[2]);
			philo[i].eat = ft_atoi(argv[3]);
			philo[i].sleep = ft_atoi(argv[4]);
			philo[i++].argcount = argc;
		}
		if (!start(philo))
			return (0);
		ft_exit(philo);
	}
	return (1);
}
