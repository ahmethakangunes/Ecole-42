/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 10:55:41 by agunes            #+#    #+#             */
/*   Updated: 2022/08/02 17:00:52 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*kms(void)
{
	char	*buff;
	int		p[2];
	int		rd_bytes;
	int		pid;

	buff = malloc(9);
	pipe(p);
	pid = fork();
	if (pid == 0)
	{
		dup2(p[1], 1);
		execve("/bin/hostname", NULL, NULL);
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

char	*ft_prompt(void)
{
	int		i;
	int		flag;
	char	*pr;
	char	*kmss;

	i = -1;
	flag = 0;
	pr = malloc(sizeof(char) * 20);
	while (g_shell->env[++i])
	{
		if (ft_strncmp(g_shell->env[i], "PWD", 3) == 0)
			break ;
	}
	if (!pr)
		return (0);
	pr = ft_strdup(getenv("USER"));
	pr = ft_strjoin(pr, "111@");
	kmss = kms();
	pr = ft_strjoin(pr, kmss);
	free(kmss);
	pr = ft_strjoin(pr, ft_strrchr(g_shell->env[i], '/') + 1);
	pr = ft_strjoin(pr, " % ");
	g_shell->promt = ft_strdup(pr);
	free(pr);
	return (g_shell->promt);
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

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		a;
	char	*array;
	size_t	len;

	a = 0;
	i = 0;
	if (s1 != NULL)
	{
		len = ft_strlen(s1) + ft_strlen(s2) + 1;
		array = (char *)malloc(sizeof(char) * (len));
		if (!array)
			return (0);
		if (array == NULL)
			return (0);
		while (s1[i] != '\0')
			array[a++] = s1[i++];
		i = 0;
		while (s2[i] != '\0')
			array[a++] = s2[i++];
		array[a] = '\0';
		free(s1);
		return (array);
	}
	return (0);
}
