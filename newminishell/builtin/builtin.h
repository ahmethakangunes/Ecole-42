/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 13:14:13 by agunes            #+#    #+#             */
/*   Updated: 2022/08/04 11:26:10 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include "../minishell.h"

int		ft_cd(char *command, char **env);
void	envupdate(char *buff, char *old, char **env);
int		ft_env(char **env);
int		ft_builtinsearch(void);
int		ft_echo(char **command);
int		ft_pwd(void);
void	ft_exit(void);
int		ft_export(char *arr, char **env);

#endif
