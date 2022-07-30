/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:41:06 by agunes            #+#    #+#             */
/*   Updated: 2022/07/30 11:50:37 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>

char	*ft_prompt(void);
int		ft_minishell(void);
char	*kms(void);
char	**ft_parser(char *s1);
void	runcommand(char **command);
void	ft_searchfor(char *arr, char **args, int a, int last);
void	ft_execve(char *arr, char *bin, char *usr, char **lst);
char	**spltnorm(char *command, int i, int k, int j);
char	**splt2norm(char *command, int i, int k, int j);

#endif
