/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 13:14:13 by agunes            #+#    #+#             */
/*   Updated: 2022/08/02 11:03:05 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "../minishell.h"

void	ft_cd(char *command, char **env);
void	envupdate(char *buff, char *old, char **env);
void	ft_env(char **env);
int		ft_builtinsearch(char **command, char **env);
void	ft_echo(char **command);
void	ft_pwd(void);
int		ft_commandsearch(char *command);
void	ft_exit(void);
void	ft_export(char *arr, char **env);
#endif