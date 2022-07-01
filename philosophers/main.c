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

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!control(argv[i]))
			return (0);
		i++;
	}
	if (!setup(argc, argv))
		return (0);
}
