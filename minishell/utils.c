/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 10:55:41 by agunes            #+#    #+#             */
/*   Updated: 2022/07/27 16:04:22 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*kms(void)
{
	char	*hostname[] = {"hostname", NULL};
	char	*buff;
	int		fd = open("test", O_RDWR);
	int		rd_bytes;
	int		pid;

	buff = malloc(1000);
	pid = fork();
	getchar();
	if (pid == 0)
	{
		dup2(fd, 1);
		execve("/bin/hostname", hostname, NULL);
	}
	else
	{
		wait(NULL);
		dup(1);
	}
	rd_bytes = read(fd, buff, 8);
	buff = ft_strjoin(buff, " % ");
	return (buff);
}

char	*ft_prompt(char **envp)
{
	int		i;
	int		flag;
	char	*pr;

	i = -1;
	flag = 0;
	pr = malloc(sizeof(char) * 20);
	if (!pr)
		return (0);	
	while (envp[++i])
	{
		if (ft_strncmp(envp[i], "USER", 4) == 0)
			break ;
	}
	pr = envp[i] + 5;
	pr = ft_strjoin(pr, "@");
	if (flag++ == 0)
		pr = ft_strjoin(pr, kms());
	return (pr);
}

char **ft_parse(char *command)
{
	command = 0;
	return (0);
}





