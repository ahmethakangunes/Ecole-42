/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 10:26:44 by scoskun           #+#    #+#             */
/*   Updated: 2022/08/04 10:55:14 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free(void)
{
	int	i;

	i = 0;
	while (g_shell->commandlist[i])
		free(g_shell->commandlist[i++]);
	i = 0;
	while (g_shell->path[i])
		free(g_shell->path[i++]);
	i = 0;
 	while(g_shell->lst[i])
		free(g_shell->lst[i++]);
	free(g_shell->lst);
}
