/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:41:06 by agunes            #+#    #+#             */
/*   Updated: 2022/08/02 17:11:04 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H


# include "libft/libft.h"
# include "builtin/builtin.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include <signal.h>

typedef struct s_shell
{
	char		**commandlist; //free
	char		**env;
	char		*command;
	char		*promt;		//free
}		t_shell;

t_shell	*g_shell;

char	*ft_prompt(void);
int		ft_strcmp(char *arr, char *arr1);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_parser(char *command);
char	**spltnorm(char *command, int i, int k, int j);
char	**splt2norm(char *command, int i, int k, int j);
void	runcommand(void);
#endif