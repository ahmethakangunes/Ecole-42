/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 11:29:59 by scoskun           #+#    #+#             */
/*   Updated: 2022/08/01 13:40:41 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


char	**ft_path(char **env)
{
	int		i;
	char	**path;

	i = -1;
	while (env[++i])
	{
		if (ft_strncmp(env[i], "PATH", 4) == 0)
			break ;
	}
	path = ft_split(env[i], ':');
	return (path);
}


void	ft_searchfor(char *arr, char **args, int last, char **path)
{
	int		i;
	int		flag;
	char	**lst;

	i = -1;
	flag = 0;
	last = 0;
	lst = malloc(100);
	while (path[++i])
	{
		path[i] = ft_strjoin(path[i], "/");
		path[i] = ft_strjoin(path[i], arr);
	}
	i = -1;
	while (args && args[++i])
		lst[i] = ft_strdup(args[i]);
	i = 0;
	while (path[i])
	{
		if (ft_execve(path[i++], lst) == -1)
			flag++;
	}
	if (flag == i)
		printf("minishell: command not found: %s\n", args[0]);
}

int	ft_execve(char *arr, char **lst)
{
	int			pid;

	pid = 0;
	pid = fork();
	if (pid == 0)
	{
		if (execve(arr, lst, NULL) == -1)
			return (-1);
	}
	else
		wait(NULL);
	return (0);
}

void	runcommand(char **command, char **env)
{
	int		i;
	int		x;
	int		pid;
	char	**path;

	i = 0;
	x = 0;
	pid = 0;
	path = ft_path(env);
	ft_builtinsearch(command, env);
	while (command[x] && command[x][0] != '|')
		x++;
	if (ft_commandsearch(command[i]))
		ft_searchfor(command[i], command, x, path);
}

int	ft_commandsearch(char *command)
{
	int	i;

	i = 0;
	if (!ft_strcmp(command, "echo"))
		return (0);
	if (!ft_strcmp(command, "cd"))
		return (0);
	if (!ft_strcmp(command, "env"))
		return (0);
	if (!ft_strcmp(command, "pwd"))
		return (0);
	if (!ft_strcmp(command, "unset"))
		return (0);
	if (!ft_strcmp(command, "exit"))
		return (0);
	if (!ft_strcmp(command, "export"))
		return (0);
	return (1);
}
