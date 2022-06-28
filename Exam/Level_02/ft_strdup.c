/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:59:10 by agunes            #+#    #+#             */
/*   Updated: 2022/06/09 11:59:11 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char	*ft_strdup(char *src)
{
	int i;
	char *arr;

	i = 0;
	while(src[i])
		i++;
	arr = malloc(sizeof(char) * i);
	i = 0;
	while(src[i])
	{
		arr[i] = src[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

int main(void)
{
	char dizi[] = "ahmet1";
	printf("%s", ft_strdup(dizi));
}