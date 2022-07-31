/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 13:14:13 by agunes            #+#    #+#             */
/*   Updated: 2022/07/31 16:37:16 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "../minishell.h"

void	ft_cd(char *command, char **env);
void	envupdate(char *buff, char *old, char **env);
void	ft_env(char **env);
int		ft_builtinsearch(char **command, char **env);
void	ft_echo(char *command);
void	ft_pwd(void);
int		ft_commandsearch(char *command);

#endif