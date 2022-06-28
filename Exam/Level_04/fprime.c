/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 12:00:00 by agunes            #+#    #+#             */
/*   Updated: 2022/06/09 12:00:01 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int asalbul(int a)
{
    int i;

    i = 2;
    while(i < a)
    {
        if(a % i == 0)
            return (0);
        i++;
    }
    return (1);
}


int    asalbolen(int a)
{
    if(a == 1)
    {
        printf("%d", 1);
        return (0);
    }
    int i;

    i = 2;
    while(i <= a)
    {
        if(asalbul(i))
        {
            while(a % i == 0)
            {
                printf("%d", i);
                if(i != a)
                    printf("*");
                a /= i;
            }
        }
        i++;
    }
    return (1);
}



int main(int argc, char **argv)
{
    if(argc == 2)
        asalbolen(atoi(argv[1]));
    return (0);
}