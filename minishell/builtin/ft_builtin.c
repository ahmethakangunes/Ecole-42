/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 12:25:49 by agunes            #+#    #+#             */
/*   Updated: 2022/08/01 11:58:38 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	ft_builtinsearch(char **command, char **env)
{
	int	flag;
	int	i;

	i = 0;
	flag = 0;
	if (!ft_strcmp(command[i], "env"))
		ft_env(env);
	if (!ft_strcmp(command[i], "cd"))
		ft_cd(command[i + 1], env);
	if (!ft_strcmp(command[i], "echo"))
	{
		ft_echo(command);
/* 		if (!ft_strcmp(command[i + 1], "-n"))
			flag = 1;
		while (command[++i] && ft_strcmp(command[i], "|"))
		{

			if (flag == 1)
				i += 1;
			ft_echo(command[i]);
			write(1, " ", 1);
		}
		if (flag != 1)
			write(1, "\n", 1); */
	}
	if (!ft_strcmp(command[i], "pwd"))
		ft_pwd();
/* 	if (ft_strcmp(command[i], "unset"))
		ft_unset(command, env);
	if (ft_strcmp(command[i], "exit"))
		ft_exit();
	if (ft_strcmp(command[i], "export"))
		ft_export(command[i], env); */
	return (1);
}
