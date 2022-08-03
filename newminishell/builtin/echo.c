/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 12:48:17 by agunes            #+#    #+#             */
/*   Updated: 2022/08/03 13:51:38 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	ft_echo(char **arg)
{
	int	i;
	int	fl;

	if (arg[1] && ft_strcmp(arg[1], "-n") == 0)
	{
		i = 2;
		fl = 1;
	}
	else
	{
		i = 1;
		fl = 0;
	}
	if (fl == 0 && arg[1] == NULL)
	{
		printf("\n");
		return ;
	}	
	while (arg[i])
	{
		if (arg[i][0] == '\"' || arg[i][0] == '\'')
			write(1, arg[i] + 1, ft_strlen(arg[i]) - 2);
		else
			write(1, arg[i], ft_strlen(arg[i]));
		if (arg[i + 1])
			write(1, " ", 1);
		i++;
	}
	if (fl == 0)
		write(1, "\n", 1);
}