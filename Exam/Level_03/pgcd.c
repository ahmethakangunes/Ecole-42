/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:59:46 by agunes            #+#    #+#             */
/*   Updated: 2022/06/09 11:59:47 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
void	bul(int a, int b)
{
	int min = a;
	int max = b;
	int temp = 0;
	int sayi = 0;
	int i = 1;
	if(min > max)
	{
		temp = max;
		max = min;
		min = temp;
	}
	while(i < max)
	{
		if(max % i == 0 && min % i == 0)
			sayi = i;
		i++;
	}
	printf("%d", sayi);
}

int main(int argc, char **argv)
{
	if(argc == 3)
		bul(atoi(argv[1]), atoi(argv[2]));
	write(1, "\n", 1);
	return (0);
}