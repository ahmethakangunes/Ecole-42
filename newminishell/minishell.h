/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 11:41:06 by agunes            #+#    #+#             */
/*   Updated: 2022/08/04 12:55:22 by agunes           ###   ########.fr       */
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

typedef struct s_token
{
	char	**path; //free
	char	**arglist; //free
	int		fd[2];
	
}	t_token;






typedef struct s_shell
{
	char		**commandlist; //free
	char		**env;
	char		**path;		//free
	char		**lst;		//free
	char		*command;
	int			pipe_flag;
	int			pipe_flag2;
	int			lstfreeflag;
}		t_shell;

t_shell	*g_shell;

char	*ft_prompt(void);
int		ft_strcmp(char *arr, char *arr1);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_parser(char *command);
char	**spltnorm(char *command, int i, int k, int j);
char	**splt2norm(char *command, int i, int k, int j);
void	runcommand(void);
int		ft_commandsearch(void);
void	ft_path(void);
void	ft_free(void);
char	*merge(char **command);

#endif
