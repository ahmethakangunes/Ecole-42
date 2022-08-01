/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 10:55:41 by agunes            #+#    #+#             */
/*   Updated: 2022/08/01 11:41:04 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*kms(void)
{
	char	**hostname;
	char	*buff;
	int		p[2];
	int		rd_bytes;
	int		pid;

	hostname = malloc(1000);
	buff = malloc(1000);
	pipe(p);
	pid = fork();
	if (pid == 0)
	{
		dup2(p[1], 1);
		execve("/bin/hostname", hostname, NULL);
	}
	else
	{
		wait(NULL);
		rd_bytes = read(p[0], buff, 8);
		buff = ft_strjoin(buff, " ");
		dup(1);
	}
	return (buff);
}

char	*ft_prompt(char **env)
{
	int		i;
	int		flag;
	char	*pr;

	i = -1;
	flag = 0;
	pr = malloc(sizeof(char) * 20);
	while (env[++i])
	{
		if (ft_strncmp(env[i], "PWD", 3) == 0)
			break ;
	}
	if (!pr)
		return (0);
	pr = getenv("USER");
	pr = ft_strjoin(pr, "111@");
	pr = ft_strjoin(pr, kms());
	pr = ft_strjoin(pr, ft_strrchr(env[i], '/') + 1);
	pr = ft_strjoin(pr, " % ");
	return (pr);
}

int	ft_strcmp(char *arr, char *arr1)
{
	int	i;

	i = 0;
	if (!arr || !arr1)
		return (-1);
	while ((arr[i] && arr1[i]))
	{
		if (arr[i] != arr1[i])
			return (-1);
		i++;
	}
	if (arr1[i] != '\0')
		return (-1);
	return (0);
}
