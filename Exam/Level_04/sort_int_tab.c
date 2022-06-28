/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 12:00:12 by agunes            #+#    #+#             */
/*   Updated: 2022/06/09 12:00:13 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void sort_int_tab(int *tab, unsigned int size)
{
    int i;
    int x;
    int temp;

    i = 0;
    temp = 0;
    x = 0;
    while(i < size)
    {
        x = 0;
        while(x < size)
        {
            if(tab[x] > tab[x + 1])
            {
                temp = tab[x];
                tab[x] = tab[x + 1];
                tab[x + 1] = temp;
            }
            x++;
        }
        i++;
    }
    i = 0;
    while(i < size)
        printf("%d", tab[i++]);
}

int main(void)
{
    int arr[] = {9,8,7,6,5,4,3,2,1};
    sort_int_tab(arr, 9);
}