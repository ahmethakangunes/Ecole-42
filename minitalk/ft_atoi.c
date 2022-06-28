/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 13:28:31 by agunes            #+#    #+#             */
/*   Updated: 2022/05/05 13:29:10 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_atoi(const char *str)
{
	int			i;
	int			minu;
	long int	temp;

	i = 0;
	temp = 0;
	minu = 1;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minu *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		temp = temp * 10 + (str[i] - 48);
		i++;
		if (temp * minu > 2147483647)
			return (-1);
		if (temp * minu < -2147483648)
			return (0);
	}
	return ((int)minu * temp);
}
/*int main()
{
	printf("r:%d t: %d", '\t', '\r');}
int main(void)
{
	const char *p = "   2147483648";
	printf("orj: %d\n", atoi(p));
	const char *k = "   2147483648";
	printf("ben: %d", ft_atoi(k));
	return 0;
}*/
