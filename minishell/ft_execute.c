/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 11:29:59 by scoskun           #+#    #+#             */
/*   Updated: 2022/07/29 19:28:49 by agunes           ###   ########.fr       */
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

void	runcommand(char **command)
{
	int	i;
	int	x;
	int	pid;

	i = 0;
	x = 0;
	pid = 0;
	while (command[x] && command[x][0] != '|')
		x++;
	ft_searchfor(command[i], command, i, x);
}
