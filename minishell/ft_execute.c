/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 11:29:59 by scoskun           #+#    #+#             */
/*   Updated: 2022/07/31 16:41:13 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_searchfor(char *arr, char **args, int a, int last)
{
	char	*usr;
	char	*bin;
	char	**lst;
	int		i;

	i = 0;
	bin = malloc(1000);
	lst = malloc(1000);
	usr = malloc(1000);
	usr = ft_strjoin(usr, "/usr/bin/");
	usr = ft_strjoin(usr, arr);
	bin = ft_strjoin(bin, "/bin/");
	bin = ft_strjoin(bin, arr);
	while (args[i] && a < last)
	{
		lst[i] = ft_strdup(args[a]);
		i++;
		a++;
	}
	ft_execve(arr, bin, usr, lst);
}

void	ft_execve(char *arr, char *bin, char *usr, char **lst)
{
	int	pid;

	pid = 0;
	pid = fork();
	if (pid == 0)
	{
		if (execve(bin, lst, NULL) != -1)
			return ;
		if (execve(usr, lst, NULL) != -1)
			return ;
		if (execve(arr, lst, NULL) == -1)
		{
			printf("evet\n");
			return ;
		}
	}
	else
		wait(NULL);
}

void	runcommand(char **command, char **env)
{
	int	i;
	int	x;
	int	pid;

	i = 0;
	x = 0;
	pid = 0;
	ft_builtinsearch(command, env);
	while (command[x] && command[x][0] != '|')
		x++;
	if (ft_commandsearch(command[i]))
		ft_searchfor(command[i], command, i, x);
}

int	ft_commandsearch(char *command)
{
	int	i;

	i = 0;
	if (ft_strcmp(command, "echo"))
		return (0);
	if (ft_strcmp(command, "cd"))
		return (0);
	if (ft_strcmp(command, "env"))
		return (0);
	if (ft_strcmp(command, "pwd"))
		return (0);
	if (ft_strcmp(command, "unset"))
		return (0);
	if (ft_strcmp(command, "exit"))
		return (0);
	if (ft_strcmp(command, "export"))
		return (0);
	return (1);
}
