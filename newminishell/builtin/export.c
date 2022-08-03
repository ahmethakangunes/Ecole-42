/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 11:00:33 by agunes            #+#    #+#             */
/*   Updated: 2022/08/03 16:23:35 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int	ft_export(char *arr, char **env)
{
	char	*buff;
	int		i;

	i = 0;
	while (env[i + 1])
		i++;
	buff = ft_strdup(env[i]);
	env[i] = arr;
	env[i + 1] = ft_strdup(buff);
	env[i + 2] = NULL;
	//arrcheck(arr, env);
	i = 0;
	return (1);
}
