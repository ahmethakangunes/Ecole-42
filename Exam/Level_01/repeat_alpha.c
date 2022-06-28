/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:58:41 by agunes            #+#    #+#             */
/*   Updated: 2022/06/09 11:58:42 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	yaz(char *s1)
{
	int i;
	int temp;

	i = 0;
	temp = 0;
	while(s1[i])
	{
		if(s1[i] >= 'a' && s1[i] <= 'z')
		{
			temp = s1[i] - 96;
			while(temp--)
				write(1, &s1[i], 1);
		}
		else if(s1[i] >= 'A' && s1[i] <= 'Z')
		{
			temp = s1[i] - 64;
			while(temp--)
				write(1, &s1[i], 1);
		}
		else
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