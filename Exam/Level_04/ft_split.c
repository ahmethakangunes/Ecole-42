/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 12:00:08 by agunes            #+#    #+#             */
/*   Updated: 2022/06/09 12:00:09 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char **ft_split(char *s1, char c)
{
    int i;
    int x;
    int y;
    char **arr;

    i = 0;
    x = 0;
    y = 0;
    arr = malloc(sizeof(char *) * 1000);
    while(s1[i] == c)
        i++;
    while(s1[i])
    {
        y = 0;
        if(s1[i] != c)
        {
            arr[x] = malloc(sizeof(char) * 100);
            while(s1[i] != c)
            {
                arr[x][y] = s1[i];
                y++;
                i++;
            }
            arr[x][y] = '\0';
            x++;
        }
        else
            i++;
    }
    arr[x] = NULL;
    return (arr);
}

int main(void)
{
    int i = 0;
    char **arr;

    arr = ft_split("ahmet hakan", ' ');
    while(i < 5)
        printf("%s\n", arr[i++]);
}