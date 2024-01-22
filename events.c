/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 18:16:07 by ablondel          #+#    #+#             */
/*   Updated: 2021/07/19 18:47:38 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_keycode(int key, t_add *add)
{
	(void)add;
	if (key == 53)
		exit(0);
	return (0);
}

int	mouse_code(int key, int x, int y, t_add *add)
{
	x = 0;
	y = 0;
	if (key == 5)
	{
		add->zoom *= pow(1.001, 155.5);
		if (add->selector == 1)
			julia_set(add);
		else
			mandelbrot_set(add);
	}
	if (key == 4)
	{
		add->zoom /= pow(1.001, 155.5);
		if (add->selector == 1)
			julia_set(add);
		else
			mandelbrot_set(add);
	}
	return (0);
}
