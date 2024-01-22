/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 18:18:17 by ablondel          #+#    #+#             */
/*   Updated: 2021/07/20 14:41:11 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_mlx(t_add *add)
{
	add->mlx_win = NULL;
	add->img = NULL;
	add->addr = NULL;
	add->bits_per_pixel = 0;
	add->line_length = 0;
	add->endian = 0;
}

void	init(t_add *add)
{
	init_mlx(add);
	add->w = 800;
	add->h = 600;
	add->zoom = 1.0;
	add->cRe = -0.7;
	add->cIm = 0.27015;
	add->pr = 0;
	add->pi = 0;
	add->newRe = 0;
	add->newIm = 0;
	add->oldRe = 0;
	add->oldIm = 0;
	add->moveX = 0;
	add->moveY = 0;
	add->c = 0;
	add->max = 255;
	add->y = 0;
	add->x = 0;
	add->i = 0;
	add->r = 121;
	add->g = 122;
	add->b = 123;
	add->selector = 1;
	add->c_switch = 1;
}
