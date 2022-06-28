/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_power_of_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:59:15 by agunes            #+#    #+#             */
/*   Updated: 2022/06/09 11:59:16 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	iki(int i)
{
	int toplam;

	toplam = 0;
	while(toplam <= i)
	{
		if(toplam == i)
			return (1);
		toplam += 2;
	}
	return (0);
}
int main(int argc, char **argv)
{
	printf("%d",iki(11));
}