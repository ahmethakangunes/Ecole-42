/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:59:25 by agunes            #+#    #+#             */
/*   Updated: 2022/06/09 11:59:26 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int  ft_strchr(char *s1, char c)
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


void yaz(char *s1, char *s2)
{
   int i;
   int len;
   char str[99];
   
   i = 0;
   len = 0;
   while(i < 99)
   {
       str[i] = '\0';
       i++;
   }
   i = 0;
   while(s1[i])
   {
       if(ft_strchr(str, s1[i]))
       {
           write(1, &s1[i], 1);
           str[len] = s1[i];
           len++;
       }
       i++;
   }
   i = 0;
    while(s2[i])
   {
       if(ft_strchr(str, s2[i]))
       {
           write(1, &s2[i], 1);
           str[len] = s2[i];
           len++;
       }
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