/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 11:14:06 by agunes            #+#    #+#             */
/*   Updated: 2022/07/27 16:31:23 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


int ft_minishell(char **envp)
{
	char	*command;
	
	command = malloc(sizeof(char) * 2048);
	while (1)
		command = readline(ft_prompt(envp));
	return (1);
}
