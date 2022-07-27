/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 10:55:41 by agunes            #+#    #+#             */
/*   Updated: 2022/07/27 11:22:30 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_prompt(char **envp)
{
	int		i;
	char	*pr;

	pr = malloc(sizeof(char) * 20);
	if (!pr)
		return (0);	
	i = -1;
	while (envp[++i])
	{
		if (ft_strncmp(envp[i], "USER", 4) == 0)
			break ;
	}
	pr = envp[i] + 5;
	pr = ft_strjoin(pr, "@minishell: ");
	return (pr);
}

char **ft_parse(char *command)
{
	
}







