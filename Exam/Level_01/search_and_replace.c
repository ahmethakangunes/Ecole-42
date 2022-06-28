/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:58:48 by agunes            #+#    #+#             */
/*   Updated: 2022/06/09 11:58:49 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	yaz(char *s1, char *s2, char *s3)
{
	int i;

	i = 0;
	while(s1[i])
	{
		if(s1[i] == s2[0])
			s1[i] = s3[0];
		write(1, &s1[i++], 1);
	}
}

int main(int argc, char **argv)
{
	if(argv[2][1] != '\0' || argv[3][1] != '\0')
	{
		write(1, "\n", 1);
		return (0);
	}
	if(argc == 4)
		yaz(argv[1], argv[2], argv[3]);
	write(1, "\n", 1);
	return (0);
}