/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scoskun <scoskun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 11:14:06 by agunes            #+#    #+#             */
/*   Updated: 2022/07/29 12:27:17 by scoskun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int ft_minishell(void)
{
	char	*command;
	char	**cmdlst;

	command = malloc(sizeof(char) * 2048);
	while (1)
	{
		command = readline(ft_prompt());
		cmdlst = ft_parser(command);
		runcommand(cmdlst);
		free(cmdlst);
		add_history(command);
	}
	return (1);
}
