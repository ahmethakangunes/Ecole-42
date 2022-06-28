/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threearg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:52:57 by agunes            #+#    #+#             */
/*   Updated: 2022/06/03 13:33:23 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	threearg(t_list *ps)
{
	if (ps->stacka[0] == ps->max && ps->stacka[1] == ps->min \
	&& ps->stacka[2] == ps->med)
	{
		rra(ps);
		rra(ps);
	}
	else if (ps->stacka[0] == ps->max && ps->stacka[1] == ps->med \
	&& ps->stacka[2] == ps->min)
	{
		sa(ps);
		rra(ps);
	}
	else if (ps->stacka[0] == ps->med && ps->stacka[1] == ps->min \
	&& ps->stacka[2] == ps->max)
		sa(ps);
	else if (ps->stacka[0] == ps->med && ps->stacka[1] == ps->max \
	&& ps->stacka[2] == ps->min)
		rra(ps);
	else if (ps->stacka[0] == ps->min && ps->stacka[1] == ps->max \
	&& ps->stacka[2] == ps->med)
	{
		rra(ps);
		sa(ps);
	}
	ft_exit(ps, 0);
}
