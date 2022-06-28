/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 13:23:00 by agunes            #+#    #+#             */
/*   Updated: 2022/06/03 13:29:49 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sameargs(t_list *ps)
{
	int	i;
	int	j;
	int	sayi;

	i = 0;
	j = 0;
	sayi = 0;
	while (i < ps->alen)
	{
		j = 0;
		sayi = 0;
		while (j < ps->alen)
		{
			if (ps->stacka[j] == ps->stacka[i])
				sayi++;
			if (sayi > 1)
				ft_exit(ps, 2);
			j++;
		}
		i++;
	}
}

void	sortcontrol(t_list *ps)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < ps->alen)
	{
		if (ps->fakea[i] == ps->stacka[i])
			j++;
		i++;
	}
	if (j == i)
		exit (0);
}
