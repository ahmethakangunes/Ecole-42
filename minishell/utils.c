/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 10:55:41 by agunes            #+#    #+#             */
/*   Updated: 2022/07/28 10:57:29 by agunes           ###   ########.fr       */
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

char	*ft_prompt(void)
{
	int		i;
	int		flag;
	char	*pr;

	i = -1;
	flag = 0;
	pr = malloc(sizeof(char) * 20);
	if (!pr)
		return (0);	
	pr = getenv("USER");
	pr = ft_strjoin(pr, "@");
	pr = ft_strjoin(pr, kms());
	return (pr);
}



