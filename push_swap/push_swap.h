/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 13:19:45 by agunes            #+#    #+#             */
/*   Updated: 2022/06/03 14:28:32 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int		*stacka;
	char	**split;
	int		*stackb;
	int		*fakea;
	int		*index;
	int		maxbit;
	int		alen;
	int		fakealen;
	int		blen;
	int		max;
	int		min;
	int		med;
}		t_list;

void	shift_up(int *arr, int len);
void	shift_down(int *arr, int len);
void	ra(t_list *ps, int len);
void	rb(t_list *ps, int len);
void	pb(t_list *ps);
void	pa(t_list *ps);
void	ft_sort(t_list *ps);
int		findindex(t_list *ps, int nbr);
void	radix(t_list *ps);
int		maxbit(t_list *ps);
void	sortcontrol(t_list *ps);
int		ft_atoi(char *s, t_list *ps);
int		isaretcontrol(char *s);
void	setup(t_list *ps, char **argv);
char	**ft_split(char const *s, char c);
void	ft_exit(t_list *ps, int x);
void	sameargs(t_list *ps);
int		argval(t_list *ps, char **argv);
void	fivearg(t_list *ps);
int		find_min(t_list *ps);
void	stackacontrol(t_list *ps);
void	sa(t_list *ps);
void	rra(t_list *ps);
void	sb(t_list *ps);
void	threearg(t_list *ps);
int		ft_printf(const char *s, ...);
#endif