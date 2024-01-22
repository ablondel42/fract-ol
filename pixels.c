/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixels.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 18:14:57 by ablondel          #+#    #+#             */
/*   Updated: 2021/07/20 14:38:47 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	ft_pixel(t_add *add, int x, int y, int color)
{
	char	*dst;

	dst = add->addr + (y * add->line_length + x * (add->bits_per_pixel) / 8);
	*(unsigned int *)dst = color;
}
