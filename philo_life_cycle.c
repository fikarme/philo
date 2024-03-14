#include "philo.h"

void	write_status(t_philo *p, char *str)
{
	pthread_mutex_lock(&p->pi->dead_mutex);
	printf("%lu %d %s\n", get_ms(p->pi), p->index + 1, str);
	pthread_mutex_unlock(&p->pi->dead_mutex);
}

void	check_eat(t_philo *p)
{
	pthread_mutex_lock(&p->pi->check_mutex);
	p->pi->eat_counter++;
	p->last_eat_time = get_ms(p->pi);
	pthread_mutex_unlock(&p->pi->check_mutex);
}

void	*philo_life_cycle(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	while (1)
	{
		pthread_mutex_lock(&p->pi->forks[p->index]);
		write_status(p, "has taken a fork");
		pthread_mutex_lock(&p->pi->forks[(p->index + 1)
			% p->pi->size_of_philo]);
		write_status(p, "has taken a fork");
		write_status(p, "is eating");
		check_eat(p);
		ms_sleep(p, p->pi->eat_time);
		write_status(p, "is sleeping");
		pthread_mutex_unlock(&p->pi->forks[p->index]);
		pthread_mutex_unlock(&p->pi->forks[(p->index + 1)
			% p->pi->size_of_philo]);
		ms_sleep(p, p->pi->sleep_time);
		write_status(p, "is thinking");
	}
	return (NULL);
}
