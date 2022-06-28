/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_13.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:58:45 by agunes            #+#    #+#             */
/*   Updated: 2022/06/09 11:58:46 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
void	yaz(char *s1)
{
	int i;

	i = 0;
	while(s1[i])
	{
		if(s1[i] >= 'a' && s1[i] <='m')
			s1[i] += 13;
		else if(s1[i] >= 'n' && s1[i] <= 'y')
			s1[i] -= 13;
		else if(s1[i] >= 'A' && s1[i] <= 'M')
			s1[i] += 13;
		else if(s1[i] >= 'N' && s1[i] <= 'Y')
			s1[i] -= 13;
		else if(s1[i] == 'z')
			s1[i] = 'm';
		else if(s1[i] == 'Z')
			s1[i] = 'M';
		write(1, &s1[i], 1);
		i++;
	}
}

int main(int argc, char **argv)
{
	if(argc == 2)
		yaz(argv[1]);
	write(1, "\n", 1);
	return (0);
}