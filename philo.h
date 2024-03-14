#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

struct	s_philo_info;

typedef struct s_philo {
	struct s_philo_info	*pi;
	pthread_t			thread;
	int					index;
	int					last_eat_time;
}	t_philo;

typedef struct s_philo_info {
	int				size_of_philo;
	unsigned long	die_time;
	int				eat_time;
	int				sleep_time;
	int				eat_limit;
	int				eat_counter;
	unsigned long	start_ms;h
	struct timeval	tv;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	dead_mutex;
	pthread_mutex_t	check_mutex;
}	t_philo_info;

// philo_life_cycle.c
void			write_status(t_philo *p, char *str);
void			check_eat(t_philo *p);
void			*philo_life_cycle(void *philo);

// philo.c
void			arguman_init(t_philo_info *pi, char **argv);
void			thread_create(t_philo_info *pi);
void			main_loop(t_philo_info *pi);

// utils.c
unsigned long	get_ms(t_philo_info *pi);
void			ms_sleep(t_philo *p, int time);
int				ft_atoi(char *str);
int				check_arguman(char **argv);

#endif