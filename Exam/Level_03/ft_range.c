/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:59:41 by agunes            #+#    #+#             */
/*   Updated: 2022/06/11 11:37:13 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
int     *ft_range(int start, int end)
{
	int i = 0;
	int *arr = malloc(sizeof(int) * 100);

	if(start <= end)
	{
		while(start < end)
		{
			arr[i] = start;
			i++;
			start++;
		}
	}
	if(start >= end)
	{
		while(start >= end)
		{
			arr[i] = start;
			start--;
			i++;
		}
	}
	return (arr);
}

int main(void)
{
	int i; 
	int *arr;

	arr = ft_range(0, -3);

	i = 0;
	while(i <= 4)
		printf("%d\n", arr[i++]);
}