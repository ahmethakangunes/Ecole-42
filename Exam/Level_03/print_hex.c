/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:59:48 by agunes            #+#    #+#             */
/*   Updated: 2022/06/09 11:59:49 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int ft_atoi(char *s1)
{
	int i;
	int sayi;
	int isaret;

	i = 0;
	sayi = 0;
	isaret = 1;
	while(s1[i] >= 0 && s1[i] <= 32)
		i++;
	if(s1[i] == '-' && s1[i] == '+')
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
void ft_putchar(char c)
{
	write(1, &c, 1);
}

void yaz(int a)
{
	char base[16] = "0123456789abcdef";
	if(a < 16)
		ft_putchar(base[a]);
	else
	{
		yaz (a / 16);
		yaz (a % 16);
	}
}

int main(int argc, char **argv)
{
	if(argc == 2)
		yaz(ft_atoi(argv[1]));
	write(1,"\n", 1);
	return (0);
}