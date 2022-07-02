/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 11:54:29 by agunes            #+#    #+#             */
/*   Updated: 2022/07/02 13:23:51 by agunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>

typedef struct s_list
{
	unsigned long int	time_to_start;
	unsigned long int	dtime;
	unsigned long int	die;
	unsigned long int	eat;
	unsigned long int	ec;
	unsigned long int	meat;
	unsigned long int	sleep;
	struct timeval		tv;
	pthread_mutex_t		*rmutex;
	pthread_mutex_t		*lmutex;
	pthread_mutex_t		*lock;
	pthread_t			thread;
	int					*rfork;
	int					*lfork;
	int					rhand;
	int					lhand;
	int					phi;
	int					id;
	int					*eatarray;
	int					*diearray;
	int					argcount;
	int					*finish;
}		t_list;

int		openmutex(t_list *philo);
int		openfork(t_list *philo);
int		samemutex(t_list *philo);
void	waitsleep(t_list *phi);
void	takefork(t_list *philo);
void	leavefork(t_list *philo);
void	get_time(t_list *philo);
int		ft_atoi(char *s1);
int		control(char *s1);
int		setup(int argc, char **argv);
void	think(t_list *philo);
int		start(t_list *philo);
void	eat(t_list *philo);
int		eatarray(t_list *philo);
void	ft_usleep(t_list *philo, unsigned long ms);
void	check_die(t_list *philo);
void	go_and_kill(t_list *philo);
int		is_finished(t_list *philo);
int		diecount(t_list *philo);
void	ft_exit(t_list *philo);
#endif