/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:33:50 by agunes            #+#    #+#             */
/*   Updated: 2022/08/04 14:56:43 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	char	*prompt;

	argc = 0;
	argv = 0;
	g_shell = malloc(sizeof(t_shell));
	g_shell->env = env;


	// PWD LEAK VERİYOR.
	while (1)
	{
		prompt = ft_prompt();
		g_shell->command = readline(prompt);
		free(prompt);
		if (g_shell->command[0] != 0)
		{
			g_shell->commandlist = ft_parser(g_shell->command);
			if (g_shell->commandlist)
			{
				runcommand();
				ft_free();
			}
			add_history(g_shell->command);
			free(g_shell->command);
		}
	}
	return (0);
}
