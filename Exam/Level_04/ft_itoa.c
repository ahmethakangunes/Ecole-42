/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 12:00:02 by agunes            #+#    #+#             */
/*   Updated: 2022/06/09 12:00:03 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int basamak(int a)
{
    int i;

    i = 0;
    if(a < 0)
        a *= -1;
    while(a)
    {
        i++;
        a /= 10;
    }
    return (i);
}

char *ft_itoa(int a)
{
    int len = basamak(a);
    int i = 0;
    char *arr = malloc(sizeof(char) * 100);
    if(a < 0)
    {
        arr[0] = '-';
        a *= -1;
        while(len > 0)
        {
            arr[len] = (a % 10) + 48;
            a /= 10;
            len--;
        }
    }
    else if(a > 0)
    {
        len--;
        while(len >= 0)
        {
            arr[len] = (a % 10) + 48;
            a /= 10;
            len--;
        }
    }
    return (arr);
}


int main(void)
{
    printf("%s", ft_itoa(123));
}