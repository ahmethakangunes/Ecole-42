/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:23:40 by agunes            #+#    #+#             */
/*   Updated: 2022/07/05 16:31:30 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_exit(t_list *philo)
{
	int	i;

	i = 0;
	while (i < philo->phi)
		pthread_mutex_destroy(&philo->freemutex[i++]);
	free(philo->freemutex);
	free(philo->freefork);
	pthread_mutex_destroy(philo->freesamemutex);
	free(philo->freediecount);
	free(philo);
}
