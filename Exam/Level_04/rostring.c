/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 12:00:11 by agunes            #+#    #+#             */
/*   Updated: 2022/06/09 12:00:12 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
char **split(char *s1, char c)
{
    int i;
    int x;
    int y;
    char **arr;

    i = 0;
    x = 0;
    y = 0;
    arr = malloc(sizeof(char *) * 100);
    while(s1[i] == c)
        i++;
    while(s1[i])
    {
        y = 0;
        if(s1[i] != c)
        {
            arr[x] = malloc(sizeof(char) * 100);
            while(s1[i] != c && s1[i])
            {
                arr[x][y] = s1[i];
                i++;
                y++;
            }
            arr[x][y] = '\0'; 
            x++;
        }
        else
            i++;
    }
    arr[x] = NULL;
    return(arr);
}

int main(int argc, char **argv)
{
    if(argc == 2)
    {
        char **arr;
        int i;
        int x;

        i = 0;
        x = 1;
        arr = split(argv[1], ' ');
        while(arr[x])
        {
            i = 0;
           while(arr[x][i])
                write(1, &arr[x][i++], 1);
            x++;
            write(1, " ", 1);
        }
        i = 0;
        x = 0;
        while(arr[0][i])
            write(1, &arr[0][i++], 1);
    }
}