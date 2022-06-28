/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:59:02 by agunes            #+#    #+#             */
/*   Updated: 2022/06/09 11:59:03 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	yaz(int a, char *s2, int b)
{
	if(s2[0] == '+')
		printf("%d", a + b);
	if(s2[0] == '-')
		printf("%d", a - b);
	if(s2[0] == '/')
		printf("%d", a / b);
	if(s2[0] == '*')
		printf("%d", a * b);
}

int main(int argc, char **argv)
{
	if(argc == 4)
		yaz(atoi(argv[1]), argv[2], atoi(argv[3]));
	return (0);
}