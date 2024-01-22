/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 18:38:07 by ablondel          #+#    #+#             */
/*   Updated: 2021/07/20 14:48:16 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	set_pos(t_add *add, double *n1, double *n2)
{
	*n1 = 1.5 * (add->x - add->w / 2) / (0.5 * add->zoom * add->w) + add->moveX;
	*n2 = (add->y - add->h / 2) / (0.5 * add->zoom * add->h) + add->moveY;
	if (add->selector == 2)
	{
		add->newRe = 0;
		add->newIm = 0;
		add->oldRe = 0;
		add->oldIm = 0;
	}
	add->i = 0;
}

void	update_pos(t_add *add, double *n1, double *n2)
{
	add->oldRe = add->newRe;
	add->oldIm = add->newIm;
	add->newRe = (add->oldRe * add->oldRe) - (add->oldIm * add->oldIm) + *n1;
	add->newIm = 2 * (add->oldRe * add->oldIm) + *n2;
}

void	update_color(t_add *add)
{
	if (add->c_switch == 1)
	{
		add->c = trgb(1, add->i * (add->r + add->i < 255),
				add->g, add->b * (add->i < add->max));
		add->c_switch = 0;
	}
	else
	{
		add->c = trgb(0, add->i * (add->r + add->i < 255),
				add->g, add->b * (add->i < add->max));
		add->c_switch = 1;
	}
	ft_pixel(add, add->x, add->y, add->c);
}

int	julia_set(t_add *add)
{
	mlx_clear_window(add->mlx, add->mlx_win);
	add->y = 0;
	while (add->y < add->h)
	{
		while (add->x < add->w)
		{
			set_pos(add, &add->newRe, &add->newIm);
			while (add->i < add->max)
			{
				update_pos(add, &add->cRe, &add->cIm);
				if ((add->newRe * add->newRe + add->newIm * add->newIm) > 4)
					break ;
				add->i++;
			}
			update_color(add);
			add->x++;
		}
		add->x = 0;
		add->y++;
	}
	mlx_put_image_to_window(add->mlx, add->mlx_win, add->img, 0, 0);
	return (0);
}

int	mandelbrot_set(t_add *add)
{
	mlx_clear_window(add->mlx, add->mlx_win);
	add->y = 0;
	while (add->y < add->h)
	{
		while (add->x < add->w)
		{
			set_pos(add, &add->pr, &add->pi);
			while (add->i < add->max)
			{
				update_pos(add, &add->pr, &add->pi);
				if ((add->newRe * add->newRe + add->newIm * add->newIm) > 4)
					break ;
				add->i++;
			}
			update_color(add);
			add->x++;
		}
		add->x = 0;
		add->y++;
	}
	mlx_put_image_to_window(add->mlx, add->mlx_win, add->img, 0, 0);
	return (0);
}
