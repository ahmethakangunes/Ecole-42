/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:59:35 by agunes            #+#    #+#             */
/*   Updated: 2022/06/11 12:22:34 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_atoi_base(const char *str, int str_base)
{
    int i;
    int sayi;
    int isaret;
    int sonuc;

    i = 0;
    sayi = 0;
    isaret = 1;
    sonuc = 0;
    while(str[i] <= 32)
        i++;
    if(str[i] == '-' || str[i] == '+')
    {
        if(str[i] == '-')
            isaret *= -1;
        i++;
    }
    while(str[i])
    {
        sonuc *= str_base;
        if(str[i] >= '0' && str[i] <= '9')
            sonuc += str[i] - 48;
        else if(str[i] >= 'a' && str[i] <= 'z')
            sonuc += str[i] - 87;
        else if(str[i] >= 'A' && str[i] <= 'Z')
            sonuc += str[i] - 55;
        i++;
    }
    return (sonuc * isaret);
}

int main(void)
{
    printf("%d", ft_atoi_base("64", 16));
}