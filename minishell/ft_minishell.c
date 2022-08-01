/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 11:14:06 by agunes            #+#    #+#             */
/*   Updated: 2022/08/01 12:27:08 by agunes           ###   ########.fr       */
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
		cmdlst = ft_parser(command);
		if(cmdlst)
		{
			runcommand(cmdlst, env);
			free(cmdlst);
		}
		add_history(command);
	}
	return (1);
}
