/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_prime_sum.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:59:31 by agunes            #+#    #+#             */
/*   Updated: 2022/06/09 11:59:32 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void ft_putchar(char s)
{
	write(1, &s, 1);
}

void ft_putnbr(int a)
{
	if(a < 10)
		ft_putchar(a + 48);
	else
	{
		ft_putnbr(a / 10);
		ft_putnbr(a % 10);
	}
}
int	ft_atoi(char *s1)
{
	int i;
	int sayi;
	int isaret;

	i = 0;
	sayi = 0;
	isaret = 1;
	while(s1[i] >= 0 && s1[i] <= 32)
		i++;
	if(s1[i] == '+' || s1[i] == '-')
	{
		if(s1[i] == '-')
			isaret *= -1;
		i++;
	}
	while(s1[i] >= '0' && s1[i] <= '9')
	{
		sayi = (sayi * 10) + (s1[i] - 48);
		i++;
	}
	return (sayi * isaret);
}

int asaltopla(int a)
{
	int i;

	i = 2;
	if(a == 1)
		return (0);
	while(i < a)
	{
		if(a % i == 0)
			return (0);
		i++;
	}
	return (a);
}


int main(int argc, char **argv)
{
	int toplam = 0;
	int i = 0;
	if(argc == 2 && ft_atoi(argv[1]) > 0)
	{
		int sayi = ft_atoi(argv[1]);
		while(i <= sayi)
			toplam += asaltopla(i++);
		ft_putnbr(toplam);
		return (0);
	}
	write(1, "0", 1);
	write(1, "\n", 1);
	return (0);
}