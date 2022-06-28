/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_word.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:59:17 by agunes            #+#    #+#             */
/*   Updated: 2022/06/09 11:59:18 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
void	yaz(char *s1)
{
	int i;

	i = 0;
	while(s1[i])
		i++;
	i--;
	while(s1[i] == ' ')
		i--;
	while(s1[i] != ' ')
		i--;
	i++;
	while(s1[i] != ' ' && s1[i] != '\0')
		write(1, &s1[i++], 1);
}

int main(int argc, char **argv)
{
	if(argc == 2)
		yaz(argv[1]);
	write(1, "\n", 1);
	return (0);
}