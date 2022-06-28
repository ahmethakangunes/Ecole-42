/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rstr_capitalizer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:59:49 by agunes            #+#    #+#             */
/*   Updated: 2022/06/09 11:59:50 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
void yaz(char *s1)
{
    int i;

    i = 0;
    while(s1[i])
    {
        if(s1[i] >= 'A' && s1[i] <= 'Z')
            s1[i] += 32;
        i++;
    }
    i = 0;
    while(s1[i] == ' ' || s1[i] == '\t')
        write(1, &s1[i++], 1);
    while(s1[i])
    {
        if(s1[i + 1] == ' ' || s1[i + 1] == '\t' || s1[i + 1] == '\0')
        {
            if(s1[i] >= 'a' && s1[i] <= 'z')
                s1[i] -= 32;
        }
        write(1, &s1[i++], 1);
    }
    write(1, "\n", 1);
}

int main(int argc, char **argv)
{
    int i;

    i = 1;
    if(argc > 1)
    while(argv[i])
        yaz(argv[i++]);
    return (0);
}