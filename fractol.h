/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablondel <ablondel@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 13:02:52 by ablondel          #+#    #+#             */
/*   Updated: 2021/07/20 14:41:02 by ablondel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define BUFFER_SIZE 1024
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include "mlx/mlx.h"
# include <limits.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_add
{
	char		*addr;
	void		*mlx;
	void		*mlx_win;
	void		*img;
	int			w;
	int			h;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	double		zoom;
	double		cRe;
	double		cIm;
	double		pr;
	double		pi;
	double		newRe;
	double		newIm;
	double		oldRe;
	double		oldIm;
	double		moveX;
	double		moveY;
	double		dec;
	double		n;
	int			c;
	int			c_switch;
	int			max;
	int			y;
	int			x;
	int			i;
	int			r;
	int			g;
	int			b;
	int			selector;
	int			neg;
	int			p;
}				t_add;

int				trgb(int t, int r, int g, int b);
void			ft_pixel(t_add *add, int x, int y, int color);
void			init(t_add *add);
int				julia_set(t_add *add);
int				mandelbrot_set(t_add *add);
int				ft_keycode(int key, t_add *add);
int				mouse_code(int key, int x, int y, t_add *add);
int				ft_atoi(char *s);
int				ft_strcmp(char *s1, char *s2);
void			setup_julia_values(t_add *add, char **av);
void			setup_mandel_values(t_add *add, char **av);
void			select_set(t_add *add, int ac, char **av);
void			usage(void);

#endif
