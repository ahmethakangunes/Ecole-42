/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 12:48:17 by agunes            #+#    #+#             */
/*   Updated: 2022/08/01 11:59:42 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

/* void	ft_echo(char *command)
{
	int	i;

	i = 0;
	while (command[i])
		i++;
	write(1, command, i);
}
 */

void	ft_echo(char **arg)
{
	int	i;
	int	fl;

	if (ft_strncmp(arg[1], "-n", 2) == 0)
	{
		i = 2;
		fl = 1;
	}
	else
	{
		i = 1;
		fl = 0;
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