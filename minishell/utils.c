/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 10:55:41 by agunes            #+#    #+#             */
/*   Updated: 2022/07/29 19:28:37 by agunes           ###   ########.fr       */
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
		buff = ft_strjoin(buff, " % ");
		dup(1);
	}
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
