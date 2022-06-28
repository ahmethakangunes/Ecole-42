/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 17:52:26 by agunes            #+#    #+#             */
/*   Updated: 2022/06/03 14:31:44 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	setup(t_list *ps, char **argv)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	k = 0;
	j = 0;
	argval(ps, argv);
	ps->stacka = malloc(sizeof(int) * ps->alen);
	ps->stackb = malloc(sizeof(int) * ps->alen);
	ps->fakea = malloc(sizeof(int) * ps->alen);
	ps->fakealen = ps->alen;
	while (argv[i])
	{
		j = 0;
		ps->split = ft_split(argv[i], ' ');
		while (ps->split[j])
			ps->stacka[k++] = ft_atoi(ps->split[j++], ps);
		j = 0;
		while (ps->split && ps->split[j])
			free(ps->split[j++]);
		if (ps->split)
			free(ps->split);
		i++;
	}
}

int	argval(t_list *ps, char **argv)
{
	int	i;
	int	j;
	int	k;

	j = 0;
	k = 0;
	i = 1;
	while (argv[i])
	{
		j = 0;
		ps->split = ft_split(argv[i], ' ');
		while (ps->split[j])
		{
			ft_atoi(ps->split[j++], ps);
			k++;
		}
		j = 0;
		while (ps->split && ps->split[j])
			free(ps->split[j++]);
		if (ps->split)
			free(ps->split);
		i++;
	}
	ps->alen = k;
	return (1);
}
