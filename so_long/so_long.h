/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 10:45:37 by agunes           #+#    #+#             */
/*   Updated: 2022/04/17 14:45:29 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "ft_printf/ft_printf.h"
//# include "libft/libft.h"

typedef struct s_list
{
	void	*mlx;
	void	*win;
	void	*player;
	void	*wall;
	void	*coll;
	void	*exit;
	char	*map;
	int		sizex;
	int		sizey;
	int		fd;
	int		index;
	int		slen;
	int		deneme;
	int		cc;
	int		x;
	int		y;
	int		pindex;
	int		movecount;
}			t_list;

int		createmap(t_list *main, char *map);
int		ft_strchr(const char *s, int c);
int		createmap(t_list *main, char *file);
int		checkmap(t_list *main);
char	*ft_read(int fd, char *left_str);
char	*ft_strdup(char *src);
size_t	ft_strlen(char *s);
void	setup(t_list *stp);
void	putimage(t_list *put);
void	moveup(t_list *main);
void	movedown(t_list *main);
void	moveright(t_list *main);
void	moveleft(t_list *main);
int		checkarray(t_list *main);
void	ft_exit(t_list *main);
char	*ft_itoa(int n);
void	ft_free(t_list *main);

#endif