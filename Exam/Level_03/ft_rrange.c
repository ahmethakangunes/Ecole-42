/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrange.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:59:42 by agunes            #+#    #+#             */
/*   Updated: 2022/06/11 11:40:36 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
int     *ft_rrange(int start, int end)
{
	int i = 0;
	int *arr = malloc(sizeof(int) * 100);

	if(start <= end)
	{
		while(end >= start)
		{
			arr[i] = end;
			end--;
			i++;
		}
	}
	if(start >= end)
	{
		while(start >= end)
		{
			arr[i] = end;
			end++;
			i++;
		}
	}
	return (arr);
}

int main(void)
{
	int *arr;
	arr = ft_rrange(1, 3);
	int i = 0;
	while(i <= 3)
	{
		printf("%d\n", arr[i++]);
	}
}