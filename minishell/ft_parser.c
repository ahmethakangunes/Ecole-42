/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 11:39:05 by agunes            #+#    #+#             */
/*   Updated: 2022/08/01 12:31:41 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_check(char *arr)
{
	int	i;
	int	d;
	int	s;

	d = 0;
	s = 0;
	i = 0;
	while (arr[i])
	{
		if (arr[i] == '"')
			d++;
		else if (arr[i] == '\'')
			s++;
		i++;
	}
	if (d % 2 != 0 || s % 2 != 0)
		return (-1);
	if (d != 0)
		return (0);
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
	j = 0;
	cmd = spltnorm(command, i, k, j);
	return (cmd);
}

char	**splt2(char *command)
{
	int		i;
	int		j;
	int		k;
	char	**cmd;

	i = 0;
	k = 0;
	j = 0;
	cmd = splt2norm(command, i, k, j);
	return (cmd);
}

char	*merge(char **command)
{
	char	*arr;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	arr = malloc(1000);
	while (command[i])
	{
		j = 0;
		while (command[i][j])
			arr[k++] = command[i][j++];
		if (command[i + 1])
			arr[k++] = ' ';
		i++;
	}
	return (arr);
}

char	**ft_parser(char *command)
{
	char	**cmd;

	if (ft_check(command) == -1)
	{
		write(2, "Syntax Error\n", 13);
		return (NULL);
	}
	if (ft_check(command) == 0)
		cmd = splt(command);
	else
		cmd = ft_split(command, ' ');
	command = merge(cmd);
	cmd = splt2(command);
	return (cmd);
}
