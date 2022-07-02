/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 21:02:54 by agunes            #+#    #+#             */
/*   Updated: 2022/07/02 13:23:28 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "philo.h"

void	ft_exit(t_list *philo)
{
	//free(philo->mutex);
	//free(philo->fork);
	free(philo->lock);
	free(philo->eatarray);
	free(philo->finish);
}