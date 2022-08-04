/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 12:53:45 by agunes            #+#    #+#             */
/*   Updated: 2022/08/04 14:56:26 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	ft_cd(char *command, char **env)
{
	char	*buff;
	char	*buff2;

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

	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], "PWD", 3))
		{
			env[i] = ft_strdup("PWD=");
			env[i] = ft_strjoin(env[i], old);
		}
		if (!ft_strncmp(env[i], "OLDPWD", 5))
		{
			env[i] = ft_strdup("OLDPWD=");
			env[i] = ft_strjoin(env[i], buff);
		}
		i++;
	}
	free(buff);
	free(old);
}
