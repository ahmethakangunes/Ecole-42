/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 17:08:36 by agunes            #+#    #+#             */
/*   Updated: 2022/08/04 16:12:40 by agunes           ###   ########.fr       */
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
	free(g_shell->path[0]);
	g_shell->path[0] = ft_strdup((ft_strchr(g_shell->path[0], '=') + 1));
	i = -1;
	while (g_shell->path[++i])
	{
		g_shell->path[i] = ft_strjoin(g_shell->path[i], "/");
		g_shell->path[i] = ft_strjoin(g_shell->path[i], \
		g_shell->commandlist[0]);
	}
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

int	ft_searchfor2(int flag, int i)
{
	while (g_shell->path[++i])
	{
		if (access(g_shell->path[i], F_OK) == 0)
		{
			flag = 2;
			ft_execve(g_shell->path[i], g_shell->lst, g_shell->env);
		}
		if (ft_strchr(g_shell->commandlist[0], '/'))
		{
			if (access(g_shell->commandlist[0], X_OK) == 0)
			{
				flag = 2;
				ft_execve(g_shell->commandlist[0], g_shell->lst, g_shell->env);
			}
			else if (access(g_shell->commandlist[0], X_OK) == -1)
				flag = 1;
		}
	}
	if (flag == 0)
	{
		printf("minishell: command not found: %s\n", \
		(ft_strrchr(g_shell->path[0], '/') + 1));
	}
	return (flag);
}

void	ft_searchfor(void)
{
	int		i;
	int		flag;

	g_shell->lstfreeflag = 0;
	i = -1;
	flag = 0;
	g_shell->lst = malloc(100);
	while (g_shell->commandlist && g_shell->commandlist[++i])
		g_shell->lst[i] = ft_strdup(g_shell->commandlist[i]);
	g_shell->lst[i] = NULL;
	i = -1;
	flag = ft_searchfor2(flag, i);
	if (flag == 1)
		printf("minishell: %s: %s\n", strerror(errno), g_shell->commandlist[0]);
}

void	runcommand(void)
{
	int		i;

	i = 0;
	//ZURNA SELAM
	if (g_shell->pipe_flag > 0)
	{
		g_shell->program = malloc(sizeof(t_token) * g_shell->pipe_flag);
		while (g_shell->commandlist[i])
		{
			g_shell->program[i] = *create_tokens(g_shell->commandlist[i]);
			i++;
		}
	}
	ft_path();
	if (ft_builtinsearch() == 0)
		ft_searchfor();
}
