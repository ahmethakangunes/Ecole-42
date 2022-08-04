/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 15:49:29 by agunes            #+#    #+#             */
/*   Updated: 2022/08/04 16:11:13 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_path1(t_token *program)
{
	int		i;

	i = -1;
	while (g_shell->env[++i])
	{
		if (ft_strncmp(g_shell->env[i], "PATH", 4) == 0)
			break ;
	}
	program->path = ft_split(g_shell->env[i], ':');
	free(program->path[0]);
	program->path[0] = ft_strdup((ft_strchr(program->path[0], '=') + 1));
	
	i = -1;
	while (program->path[++i])
	{
		program->path[i] = ft_strjoin(program->path[i], "/");
		program->path[i] = ft_strjoin(program->path[i], \
		program->command[0]);
	}
}

t_token	*create_tokens(char *commandlist)
{
	t_token	*program;

	program = malloc(sizeof(t_token));
	program->command = ft_split(commandlist, ' ');
	ft_path1(program);
	int i = 0;
	while(program->path[i])
		printf("%s\n", program->path[i++]);
	getchar();
	return (program);
}