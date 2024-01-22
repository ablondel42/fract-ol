/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 16:48:55 by ablondel          #+#    #+#             */
/*   Updated: 2021/07/19 19:28:03 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	usage(void)
{
	printf("Hello and welcome to Fract-ol!\n");
	printf("To launch the julia set: ./fractol julia\n");
	printf("To launch the mandelbrot set: ./fractol mandelbrot\n\n");
	printf("You can add 4 arguments:\n");
	printf("Argument 1 should be a value between 1 and 255\n");
	printf("This value represents the number of iterations to be rendered\n\n");
	printf("Argument 2 should be a value between 1 and 255\n");
	printf("This value represents the amount of red\n\n");
	printf("Argument 3 should be a value between 1 and 255\n");
	printf("This value represents the amount of green\n\n");
	printf("Argument 4 should be a value between 1 and 255\n");
	printf("This value represents the amount of blue\n\n");
}

void	starter(t_add *add)
{
	add->mlx = mlx_init();
	if (!add->mlx)
		exit(EXIT_FAILURE);
	add->mlx_win = mlx_new_window(add->mlx, add->w, add->h, "Fract-ol");
	if (!add->mlx_win)
		exit(EXIT_FAILURE);
	add->img = mlx_new_image(add->mlx, add->w, add->h);
	if (!add->img)
		exit(EXIT_FAILURE);
	add->addr = mlx_get_data_addr(add->img, &add->bits_per_pixel,
			&add->line_length, &add->endian);
	if (!add->img)
		exit(EXIT_FAILURE);
}

int	main(int ac, char **av)
{
	t_add	add;

	init(&add);
	if (ac >= 2)
	{
		select_set(&add, ac, av);
		starter(&add);
		if (add.selector == 1)
			julia_set(&add);
		else
			mandelbrot_set(&add);
		mlx_hook(add.mlx_win, 2, 1L << 1, &ft_keycode, &add);
		mlx_mouse_hook(add.mlx_win, &mouse_code, &add);
		mlx_loop(add.mlx);
	}
	usage();
}
