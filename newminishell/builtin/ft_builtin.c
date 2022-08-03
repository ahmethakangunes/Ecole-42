/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 12:25:49 by agunes            #+#    #+#             */
/*   Updated: 2022/08/03 13:50:12 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	ft_builtinsearch(void)
{
	if (!ft_strcmp(g_shell->commandlist[0], "env"))
		ft_env(g_shell->env);
	if (!ft_strcmp(g_shell->commandlist[0], "cd"))
		ft_cd(g_shell->commandlist[1], g_shell->env);
	if (!ft_strcmp(g_shell->commandlist[0], "echo"))
		ft_echo(g_shell->commandlist);
	if (!ft_strcmp(g_shell->commandlist[0], "pwd"))
		ft_pwd();
	if (!ft_strcmp(g_shell->commandlist[0], "exit"))
		ft_exit();
	if (!ft_strcmp(g_shell->commandlist[0], "export"))
		ft_export(g_shell->commandlist[1], g_shell->env);
/* 	if (ft_strcmp(g_shell->commandlist[0], "unset"))
		ft_unset(g_shell->commandlist, g_shell->env); */
	return (1);
}
