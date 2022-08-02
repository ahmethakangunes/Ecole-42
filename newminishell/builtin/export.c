/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 11:00:33 by agunes            #+#    #+#             */
/*   Updated: 2022/08/02 13:29:59 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	checkequal(char *arr)
{
	int	i;
	int	c;

	c = 0;
	i = -1;
	while (arr[++i])
	{
		if (arr[i] == '=')
			c++;
		if (c >= 3)
			return (-1);
	}
	if (c == 2)
		return (1);
	if (c == 1)
		return (2);
	return (0);
}


int	arrcheck(char *arr, char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH", 4) == 0)
			break ;
		i++;
	}
	i = 0;
	if (checkequal(arr) == 2)
	{
		while (access(env[i], F_OK) != 0)
		{

		}
		if (env[i] != NULL)
			arr = ft_strjoin(ft_strrchr(arr, '=') + 1, env[i]);
	}
	return (1);
}

void	ft_export(char *arr, char **env)
{
	char	*buff;
	int		i;

	i = 0;
	while (env[i + 1])
		i++;
	buff = ft_strdup(env[i]);
	env[i] = arr;
	env[i + 1] = ft_strdup(buff);
	env[i + 2] = NULL;
	//arrcheck(arr, env);
	i = 0;
}
