/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agunes <agunes@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 11:54:29 by agunes            #+#    #+#             */
/*   Updated: 2022/06/28 19:38:46 by agunes           ###   ########.fr       */
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
	pthread_mutex_t		*rmutex;
	pthread_mutex_t		*lmutex;
	pthread_mutex_t		*lock;
	pthread_t			thread;
	struct timeval		tv;
	int					rhand;
	int					lhand;
	int					phi;
	int					id;
	int					ec;
	int					meat;
	int					*eatarray;
	int					*diearray;
	int					die;
	int					eat;
	int					argcount;
	int					sleep;
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
void	meal(t_list *philo);
void	mealcheck(t_list *philo);
int		eatarray(t_list *philo);
int		diearray(t_list *philo);

#endif