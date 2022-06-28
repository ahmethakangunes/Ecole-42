/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hidenp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:59:43 by agunes            #+#    #+#             */
/*   Updated: 2022/06/09 11:59:44 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
int	yaz(char *s1, char *s2)
{
	int i;
	int x;
	int len;

	i = 0;
	len = 0;
	x = 0;
	while(s1[i])
	{
		x = 0;
		while(s2[x])
		{
			if(s2[x] == s1[i])
				len++;
			x++;
		}
		if(len == 0)
			return (0);
		i++;
	}
	if(len >= i)
		return (1);
	return (0);
}

int main(int argc, char **argv)
{
	if(argc == 3)
		printf("%d",yaz(argv[1], argv[2]));
	write(1, "\n", 1);
	return (0);
}