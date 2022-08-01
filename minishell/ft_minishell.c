/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 11:14:06 by agunes            #+#    #+#             */
/*   Updated: 2022/08/01 15:06:49 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_minishell(char **env)
{
	char	*command;
	char	**cmdlst;

	command = malloc(sizeof(char) * 2048);
	while (1)
	{
		command = readline(ft_prompt(env));
		if (command[0] != 0)
		{
			cmdlst = ft_parser(command);
			runcommand(cmdlst, env);
			free(cmdlst);
			add_history(command);
		}
	}
	return (1);
}
