/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wdmatch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:59:27 by agunes            #+#    #+#             */
/*   Updated: 2022/06/09 11:59:28 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    yaz(char *s1, char *s2)
{
    int i;
    int y;
    int x;
    int len;

    i = 0;
    x = 0;
    y = 0;
    len = 0;
    while(s1[y])
        y++;
    while(s1[i])
    {
        while(s2[len])
        {
            if(s1[i] == s2[len])
            {
                x++;
                break;
            }
            len++;
        }
        i++;
    }
    i = 0;
    if(x == y)
    {
        while(s1[i])
            write(1, &s1[i++], 1);
    }
}


int main(int argc, char **argv)
{
    if(argc == 3)
        yaz(argv[1], argv[2]);
    write(1, "\n", 1);
    return (0);
}