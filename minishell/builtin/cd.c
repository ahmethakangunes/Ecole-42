/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 12:53:45 by agunes            #+#    #+#             */
/*   Updated: 2022/07/31 12:34:45 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	ft_cd(char *command, char **env)
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
}

void	envupdate(char *buff, char *old, char **env)
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strcmp(env[i], "PWD"))
		{
			env[i] = ft_strdup("PWD=");
			env[i] = ft_strjoin(env[i], old);
		}
		if (ft_strcmp(env[i], "OLDPWD"))
		{
			env[i] = ft_strdup("OLDPWD=");
			env[i] = ft_strjoin(env[i], buff);
		}
		i++;
	}
}
