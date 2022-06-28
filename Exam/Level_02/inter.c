/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:59:14 by agunes            #+#    #+#             */
/*   Updated: 2022/06/09 11:59:15 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int ft_strchr(char *s1, char c)
{
    int i;

    i = 0;
    while(s1[i])
    {
        if(s1[i] == c)
            return (0);
        i++;
    }
    return (1);
}


void    yaz(char *s1, char *s2)
{
    int i = 0;
    int x = 0;
    int len = 0;
    char str[99];

    while(i < 99)
        str[i++] = '\0';
    i = 0;
    while(s1[i])
    {
        x = 0;
        len = 0;
        while(s2[x])
        {
            if(s1[i] == s2[x])
                len++;
            x++;
        }
        if(len > 0 && ft_strchr(str, s1[i]))
            write(1, &s1[i], 1);
        str[i] = s1[i]; 
        i++;
    }
}




int main(int argc, char **argv)
{
    if(argc == 3)
        yaz(argv[1], argv[2]);
    write(1, "\n", 1);
    return (0);
}