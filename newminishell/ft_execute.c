/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 17:08:36 by agunes            #+#    #+#             */
/*   Updated: 2022/08/03 15:25:47 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_path(void)
{
	int		i;

	i = -1;
	while (g_shell->env[++i])
	{
		if (ft_strncmp(g_shell->env[i], "PATH", 4) == 0)
			break ;
	}
	g_shell->path = ft_split(g_shell->env[i], ':');
	g_shell->path[0] = ft_strdup((ft_strchr(g_shell->path[0], '=') + 1));
}

int	ft_execve(char *arr, char **lst, char **env)
{
	int			pid;

	pid = 0;
	pid = fork();
	if (pid == 0)
	{
		execve(arr, lst, env);
		kill(getpid(), SIGTERM);
	}
	else
	{
		wait(NULL);
	}
	return (0);
}

void	ft_searchfor(void)
{
	int		i;
	int		flag;
	char	**lst;

	i = -1;
	flag = 0;
	lst = malloc(100);
	while (g_shell->path[++i])
	{
		g_shell->path[i] = ft_strjoin(g_shell->path[i], "/");
		g_shell->path[i] = ft_strjoin(g_shell->path[i], \
		g_shell->commandlist[0]);
	}
	i = -1;
	while (g_shell->commandlist && g_shell->commandlist[++i])
		lst[i] = ft_strdup(g_shell->commandlist[i]);
	lst[i] = NULL;
	i = -1;
	while (g_shell->path[++i])
	{
		if (access(g_shell->path[i], F_OK) == 0)
		{
			flag = 2;
			ft_execve(g_shell->path[i], lst, g_shell->env);
			break ;
		}
		if (ft_strchr(g_shell->commandlist[0], '/'))
		{
			if (access(g_shell->commandlist[0], X_OK) == 0)
			{
				flag = 2;
				ft_execve(g_shell->commandlist[0], lst, g_shell->env);
				break ;
			}
			else if (access(g_shell->commandlist[0], X_OK) == -1)
				flag = 1;
		}
	}
	if (flag == 0)
	{
		printf("zsh: command not found: %s\n", \
		(ft_strrchr(g_shell->path[0], '/') + 1));
	}
	if (flag == 1)
		printf("%s\n", strerror(errno));
}

void	runcommand(void)
{
	int		i;

	i = 0;
	ft_path();
	ft_builtinsearch();
	if (ft_commandsearch())
		ft_searchfor();
}

int	ft_commandsearch(void)
{
	int	i;

	i = 0;
	if (!ft_strcmp(g_shell->commandlist[0], "echo"))
		return (0);
	if (!ft_strcmp(g_shell->commandlist[0], "cd"))
		return (0);
	if (!ft_strcmp(g_shell->commandlist[0], "env"))
		return (0);
	if (!ft_strcmp(g_shell->commandlist[0], "pwd"))
		return (0);
	if (!ft_strcmp(g_shell->commandlist[0], "unset"))
		return (0);
	if (!ft_strcmp(g_shell->commandlist[0], "exit"))
		return (0);
	if (!ft_strcmp(g_shell->commandlist[0], "export"))
		return (0);
	return (1);
}
