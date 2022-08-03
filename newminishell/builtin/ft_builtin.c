/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 12:25:49 by agunes            #+#    #+#             */
/*   Updated: 2022/08/03 16:24:09 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	ft_builtinsearch(void)
{
	if (!ft_strcmp(g_shell->commandlist[0], "env"))
		return (ft_env(g_shell->env));
	if (!ft_strcmp(g_shell->commandlist[0], "cd"))
		return (ft_cd(g_shell->commandlist[1], g_shell->env));
	if (!ft_strcmp(g_shell->commandlist[0], "echo"))
		return (ft_echo(g_shell->commandlist));
	if (!ft_strcmp(g_shell->commandlist[0], "pwd"))
		return (ft_pwd());
	if (!ft_strcmp(g_shell->commandlist[0], "exit"))
		ft_exit();
	if (!ft_strcmp(g_shell->commandlist[0], "export"))
		return (ft_export(g_shell->commandlist[1], g_shell->env));
/* 	if (ft_strcmp(g_shell->commandlist[0], "unset"))
		ft_unset(g_shell->commandlist, g_shell->env); */
	return (0);
}
