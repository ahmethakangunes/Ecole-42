/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 11:39:05 by agunes            #+#    #+#             */
/*   Updated: 2022/07/29 12:35:56 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check(char *arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		if (arr[i] == '"')
			return (0);
		i++;
	}
	return (1);
}

char	**splt(char *command)
{
	int		i;
	int		j;
	int		k;
	char	**cmd;

	i = -1;
	k = 0;
	cmd = malloc(sizeof(char *) * 10);
	while (command[++i])
	{
		j = 0;
		if (command[i] != '"' && command[i] != ' ')
		{
			cmd[k] = malloc(sizeof(char) * 1000);
			while (command[i] && command[i] != '"' && command[i] != ' ')
				cmd[k][j++] = command[i++];
			cmd[k++][j] = '\0';
		}
		if (command[i] == '"')
		{
			i++;
			cmd[k] = malloc(sizeof(char) * 1000);
			j = 0;
			while (command[i] && command[i] != '"')
				cmd[k][j++] = command[i++];
			cmd[k++][j] = '\0';
		}
	}
	cmd[k] = NULL;
	return (cmd);
}

char **splt2(char *command)
{
	int		i;
	int		j;
	int		k;
	char	**cmd;

	i = 0;
	k = 0;
	cmd = malloc(sizeof(char *) * 16);
	while (command[i])
	{
		j = 0;
		if ((command[i] != '>' && command[i] != '<') && command[i] != ' ')
		{
			cmd[k] = malloc(sizeof(char) * 1000);
			while (command[i] && command[i] != ' ' && (command[i] != '>' && command[i] != '<'))
				cmd[k][j++] = command[i++];
			cmd[k++][j] = '\0';
		}
		if (command[i] == '>' || command[i] == '<')
		{
			j = 0;
			cmd[k] = malloc(sizeof(char) * 100);
			cmd[k][j++] = command[i];
			cmd[k][j] = '\0';
			k++;
		}
		i++;
	}
	cmd[k] = NULL;
	return(cmd);
}

char *merge(char **command)
{
	char *arr;
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	arr = malloc(1000);
	while(command[i])
	{
		j = 0;
		while(command[i][j])
			arr[k++] = command[i][j++];
		if (command[i + 1])
			arr[k++] = ' ';
		i++;
	}
	return (arr);
}

char **ft_parser(char *command)
{
	char	**cmd;

	if (!ft_check(command))
		cmd = splt(command);
	else
		cmd = ft_split(command, ' ');
	command = merge(cmd);
	cmd = splt2(command);
	return (cmd);
}
