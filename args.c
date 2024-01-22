/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 18:17:01 by ablondel          #+#    #+#             */
/*   Updated: 2021/07/19 19:28:48 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_atoi(char *s)
{
	int	neg;
	int	n;

	neg = 1;
	n = 0;
	while (*s == '\v' || *s == '\r' || *s == '\t'
		|| *s == '\f' || *s == '\n' || *s == ' ')
		s++;
	while (*s == '+' || *s == '-')
	{
		if (*s == '-')
			neg *= -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
		n = n * 10 + *s++ - '0';
	if ((n * neg) >= 0 && (n * neg) <= 255)
		return (n * neg);
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	if (!s1 || !s2)
		return (1);
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void	setup_julia_values(t_add *add, char **av)
{
	add->max = ft_atoi(av[2]);
	if (add->max < 1 || add->max > 255)
		exit(EXIT_FAILURE);
	add->r = ft_atoi(av[3]);
	add->g = ft_atoi(av[4]);
	add->b = ft_atoi(av[5]);
	if (add->r == 0 || add->g == 0 || add->b == 0)
		exit(EXIT_FAILURE);
}

void	setup_mandel_values(t_add *add, char **av)
{
	add->max = ft_atoi(av[2]);
	if (add->max < 1 || add->max > 255)
		exit(EXIT_FAILURE);
	add->r = ft_atoi(av[3]);
	add->g = ft_atoi(av[4]);
	add->b = ft_atoi(av[5]);
	if (add->r == 0 || add->g == 0 || add->b == 0)
		exit(EXIT_FAILURE);
}

void	select_set(t_add *add, int ac, char **av)
{
	if (ft_strcmp(av[1], "julia") == 0)
		add->selector = 1;
	else if (ft_strcmp(av[1], "mandelbrot") == 0)
		add->selector = 2;
	else
	{
		usage();
		exit(EXIT_FAILURE);
	}
	if (add->selector == 1)
		if (ac == 6)
			setup_julia_values(add, av);
	if (add->selector == 2)
		if (ac == 6)
			setup_mandel_values(add, av);
}
