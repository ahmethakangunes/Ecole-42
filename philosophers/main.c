/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:24:49 by agunes            #+#    #+#             */
/*   Updated: 2022/06/27 13:38:56 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	control(char *s1)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (!(s1[i] >= '0' && s1[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	setup(int argc, char **argv)
{
	t_list		*philo;
	int			i;

	i = 0;
	if (argc == 5 || argc == 6)
	{
		philo = malloc(sizeof(t_list) * ft_atoi(argv[1]));
		philo->phi = ft_atoi(argv[1]);
		while (i < philo->phi)
		{
			philo[i].id = i + 1;
			philo[i].phi = ft_atoi(argv[1]);
			philo[i].die = ft_atoi(argv[2]);
			philo[i].eat = ft_atoi(argv[3]);
			philo[i].sleep = ft_atoi(argv[4]);
			if (argc == 6)
				philo[i].meat = ft_atoi(argv[5]);
			i++;
		}
		if (!start(philo))
			return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
		if (!control(argv[i++]))
			return (0);
	if (!setup(argc, argv))
		return (0);
}
