#include "philo.h"

int	main(int ac, char **argv)
{
	t_philo_info	*pi;

	pi = malloc(sizeof(t_philo_info));
	if ((ac != 5 && ac != 6) || check_arguman(argv + 1) == -1)
		return (1);
	arguman_init(pi, argv);
	thread_create(pi);
	main_loop(pi);
	return (0);
}

void	arguman_init(t_philo_info *pi, char **argv)
{
	pi->size_of_philo = ft_atoi(argv[1]);
	pi->die_time = ft_atoi(argv[2]);
	pi->eat_time = ft_atoi(argv[3]);
	pi->sleep_time = ft_atoi(argv[4]);
	if (argv[5])
		pi->eat_limit = ft_atoi(argv[5]);
	else
		pi->eat_limit = -1;
	pi->eat_counter = 0;
	pi->philos = malloc(sizeof(t_philo) * pi->size_of_philo);
	pi->forks = malloc(sizeof(pthread_mutex_t) * pi->size_of_philo);
	gettimeofday(&pi->tv, NULL);
	pi->start_ms = (pi->tv.tv_usec / 1000 + pi->tv.tv_sec * 1000);
}

void	thread_create(t_philo_info *pi)
{
	int	i;

	i = -1;
	pthread_mutex_init(&pi->dead_mutex, NULL);
	pthread_mutex_init(&pi->check_mutex, NULL);
	while (++i < pi->size_of_philo)
		pthread_mutex_init(&pi->forks[i], NULL);
	i = -1;
	while (++i < pi->size_of_philo)
	{
		pi->philos[i].pi = pi;
		pi->philos[i].last_eat_time = get_ms(pi);
		pi->philos[i].index = i;
		if (pthread_create(&pi->philos[i].thread, NULL, philo_life_cycle,
				&pi->philos[i]) != 0)
			printf("Error.\n");
		usleep(100);
	}
}

void	main_loop(t_philo_info *pi)
{
	int	i;

	i = 1;
	while (1)
	{
		pthread_mutex_lock(&pi->check_mutex);
		if (pi->eat_limit != -1 && pi->eat_counter >= pi->eat_limit
			* pi->size_of_philo)
		{
			pthread_mutex_lock(&pi->dead_mutex);
			return ;
		}
		if (get_ms(pi) - pi->philos[i % pi->size_of_philo].last_eat_time
			>= pi->die_time)
		{
			pthread_mutex_lock(&pi->dead_mutex);
			printf("%lu %d died\n", get_ms(pi),
				(i % pi->size_of_philo) + 1);
			return ;
		}
		pthread_mutex_unlock(&pi->check_mutex);
		i++;
		usleep(100);
	}
}
