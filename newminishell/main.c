/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:33:50 by agunes            #+#    #+#             */
/*   Updated: 2022/08/03 12:42:39 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	argc = 0;
	argv = 0;
	g_shell = malloc(sizeof(g_shell));
	g_shell->env = env;
	while (1)
	{
		g_shell->command = readline("minishell % ");
		free(g_shell->promt);
		if (g_shell->command[0] != 0)
		{
			printf("test\n");
			g_shell->commandlist = ft_parser(g_shell->command);
			if (g_shell->commandlist)
			{
				runcommand();
				free(g_shell->commandlist);
			}
			add_history(g_shell->command);
		}
	}
	return (0);
}
