/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 13:14:13 by agunes            #+#    #+#             */
/*   Updated: 2022/08/03 13:42:27 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "../minishell.h"

void	ft_cd(char *command, char **env);
void	envupdate(char *buff, char *old, char **env);
void	ft_env(char **env);
int		ft_builtinsearch(void);
void	ft_echo(char **command);
void	ft_pwd(void);
void	ft_exit(void);
void	ft_export(char *arr, char **env);
#endif