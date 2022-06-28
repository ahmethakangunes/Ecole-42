/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:59:08 by agunes            #+#    #+#             */
/*   Updated: 2022/06/09 11:59:09 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t i;
	size_t x;

	i = 0;
	x = 0;
	while(s[i])
	{
		x = 0;
		while(reject[x])
		{
			if(s[i] == reject[x])
				return (i);
			x++;
		}
		i++;
	}
	i = 0;
	while(s[i])
		i++;
	return (i);
}

int main(void)
{
	char dizi[] = "ahmet";
	char dizi2[] = "xet";
	printf("%d\n", ft_strcspn(dizi, dizi2));
	printf("%d", strcspn(dizi, dizi2));
}