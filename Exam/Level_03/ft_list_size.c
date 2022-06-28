/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:59:37 by agunes            #+#    #+#             */
/*   Updated: 2022/06/09 11:59:39 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>
#include <stdlib.h>
int	ft_list_size(t_list *begin_list)
{
	int i;

	i = 0;
	while(begin_list)
	{
		begin_list = begin_list->next;
		i++;
	}
	return (i);
}

int main(void)
{
	t_list *test;
	t_list *test2;
	t_list *test3;

	test = malloc(100);
	test2 = malloc(100);
	test3 = malloc(100);

	test->next = test2;
	test2->next = test3;
	printf("%d",ft_list_size(test));
}