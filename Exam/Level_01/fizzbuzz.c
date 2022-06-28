/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:58:20 by agunes            #+#    #+#             */
/*   Updated: 2022/06/09 11:58:21 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void ft_putchar(char s)
{
	write(1, &s, 1);
}

void ft_putnbr(int i)
{
	if(i < 10)
		ft_putchar(i + 48);
	else
	{
		ft_putnbr(i / 10);
		ft_putnbr(i % 10);
	}
}

void	fizzbuzz(int i)
{
	while(i < 100)
	{
		if (i % 3 == 0 && i % 5 == 0)
			write(1, "fizzbuzz", 8);
		else if(i % 3 == 0)
			write(1, "fizz", 4);
		else if(i % 5 == 0)
			write(1, "buzz", 4);
		else
			ft_putnbr(i);
		write(1, "\n", 1);
		i++;
	}
}

int main(void)
{
	int i;

	i = 1;
	fizzbuzz(i);
}