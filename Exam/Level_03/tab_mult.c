/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_mult.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:59:53 by agunes            #+#    #+#             */
/*   Updated: 2022/06/09 11:59:54 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int ft_atoi(char *s1)
{
    int i;
    int sayi;

    i = 0;
    sayi = 0;
    while(s1[i] >= '0' && s1[i] <= '9')
    {
        sayi = (sayi * 10) + (s1[i] - 48);
        i++;
    }
    return (sayi);
}

void ft_putchar(char c)
{
    write(1, &c, 1);
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
void    carpim(int a)
{
    int i;

    i = 1;
    while(i < 10)
    {
        ft_putnbr(i);
        write(1, " ", 1);
        write(1, "*", 1);
        write(1, " ", 1);
        ft_putnbr(a);
        write(1, " ", 1);
        write(1, "=", 1);
        write(1, " ", 1);
        ft_putnbr(i * a);
        write(1, "\n", 1);
        i++;
    }
}

int main(int argc, char **argv)
{
    if(argc == 2)
        carpim(ft_atoi(argv[1]));
    else
        write(1, "\n", 1);
    return (0);
}