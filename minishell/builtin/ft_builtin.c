/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 12:25:49 by agunes            #+#    #+#             */
/*   Updated: 2022/07/30 14:40:47 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	ft_builtinsearch(char **command, char **env)
{
	int	i;

	i = 0;
	if (ft_strcmp(command[i], "env"))
		ft_env(env);
	if (ft_strcmp(command[i], "cd"))
		ft_cd(command[i + 1], env);
/* 	if (ft_strcmp(command[i], "echo"))
		ft_echo(command);
	if (ft_strcmp(command[i], "unset"))
		ft_unset(command, env);
	if (ft_strcmp(command[i], "pwd"))
		ft_pwd();
	if (ft_strcmp(command[i], "exit"))
		ft_exit();
	if (ft_strcmp(command[i], "export"))
		ft_export(command[i], env); */
	return (1);
}
