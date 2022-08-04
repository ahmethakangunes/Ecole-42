/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 12:53:45 by agunes            #+#    #+#             */
/*   Updated: 2022/08/04 13:25:24 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	ft_cd(char *command, char **env)
{
	char	*buff;
	char	*buff2;

	buff = malloc(sizeof(char) * 2048);
	buff2 = malloc(sizeof(char) * 2048);
	if (!command)
	{
		buff = getcwd(NULL, 0);
		chdir(getenv("HOME"));
		buff2 = getcwd(NULL, 0);
		envupdate(buff, buff2, env);
	}
	else
	{
		buff = getcwd(NULL, 0);
		chdir(command);
		buff2 = getcwd(NULL, 0);
		envupdate(buff, buff2, env);
	}
	return (1);
}

void	envupdate(char *buff, char *old, char **env)
{
	int		i;
	char	*a;

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PWD", 3))
		{
			a = old;
			env[i] = ft_strdup("PWD=");
			env[i] = ft_strjoin(env[i], old);
			free(a);
		}
		if (!ft_strncmp(env[i], "OLDPWD", 5))
		{
			a = buff;
			env[i] = ft_strdup("OLDPWD=");
			env[i] = ft_strjoin(env[i], buff);
			free(a);
		}
		i++;
	}
}
