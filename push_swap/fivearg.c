/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fivearg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 12:48:59 by agunes            #+#    #+#             */
/*   Updated: 2022/05/30 17:49:41 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fivearg(t_list *ps)
{
	int	i;

	i = 0;
	ps->max = ps->fakea[4];
	ps->min = ps->fakea[0];
	ps->med = ps->fakea[3];
	while (ps->blen < 2)
	{
		if (ps->stacka[0] == ps->min || ps->stacka[0] == ps->max || \
		ps->stacka[0] == ps->med)
			ra(ps, ps->alen);
		else
			pb(ps);
	}
	stackacontrol(ps);
	if (ps->stackb[0] < ps->stackb[1])
		sb(ps);
	while (ps->blen)
		pa(ps);
	rra(ps);
	ft_exit(ps, 0);
}

void	stackacontrol(t_list *ps)
{
	if (ps->stacka[0] == ps->min && ps->stacka[1] == ps->med \
	&& ps->stacka[2] == ps->max)
		ra(ps, ps->alen);
	else if (ps->stacka[0] == ps->med && ps->stacka[1] == ps->min \
	&& ps->stacka[2] == ps->max)
	{
		rra(ps);
		sa(ps);
	}
	else if (ps->stacka[0] == ps->max && ps->stacka[1] == ps->med \
	&& ps->stacka[2] == ps->min)
		sa(ps);
	else if (ps->stacka[0] == ps->max && ps->stacka[1] == ps->min \
	&& ps->stacka[2] == ps->med)
		rra(ps);
	else if (ps->stacka[0] == ps->min && ps->stacka[1] == ps->max \
	&& ps->stacka[2] == ps->med)
	{
		ra(ps, ps->alen);
		sa(ps);
	}
}

void	sa(t_list *ps)
{
	int	temp;

	temp = ps->stacka[0];
	ps->stacka[0] = ps->stacka[1];
	ps->stacka[1] = temp;
	ft_printf("sa\n");
}

void	rra(t_list *ps)
{
	int		temp;

	temp = ps->stacka[ps->alen - 1];
	shift_down(ps->stacka, ps->alen);
	ps->stacka[0] = temp;
	ft_printf("rra\n");
}

void	sb(t_list *ps)
{
	int	temp;

	temp = ps->stackb[0];
	ps->stackb[0] = ps->stackb[1];
	ps->stackb[1] = temp;
	ft_printf("sb\n");
}
