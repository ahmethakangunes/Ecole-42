/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:41:03 by agunes            #+#    #+#             */
/*   Updated: 2022/07/27 11:16:12 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char **argv, char **envp)
{
	argc = 0;
	argv = 0;
	int	i;
	int pid;

	i = 0;
	pid = 0;
	if (!ft_minishell(envp))
		return (0);
}
