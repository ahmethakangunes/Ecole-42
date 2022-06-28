/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:58:34 by agunes            #+#    #+#             */
/*   Updated: 2022/06/11 12:25:51 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int main(void)
{
	int a;
	int b;

	a = 4;
	b = 5;
	printf("swap öncesi a = %d b = %d\n", a,b);
	ft_swap(&a, &b);
	printf("swap sonrası a = %d b = %d\n", a,b);
}