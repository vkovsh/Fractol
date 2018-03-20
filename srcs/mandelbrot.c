/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 16:12:55 by vkovsh            #+#    #+#             */
/*   Updated: 2018/01/26 18:33:22 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		set_options(t_terrain *t, t_set *set)
{
	set->def = set_color(0, 0, 0);
	set->y_max = H_HEIGHT - t->y_abs;
	set->x_max = H_WIDTH - t->x_abs + t->x_until - WIDTH;
	set->y_split = H_HEIGHT + t->y_abs;
	set->x_split = H_WIDTH + t->x_abs;
	set->y = -H_HEIGHT - t->y_abs;
	set->y_coord = set->y + set->y_split;
	set->step = 1 / t->z;
}

static void		do_put(t_terrain *t)
{
	int			x;
	t_complex	c;
	t_set		set;

	set_options(t, &set);
	c.im = set.y / t->z;
	while (++set.y < set.y_max)
	{
		x = -set.x_split + t->x_start;
		c.im += set.step;
		set.y_coord++;
		c.re = x / t->z;
		while (++x < set.x_max)
		{
			c.re += set.step;
			if (!((set.res = t->checker(c, t)) == t->iter))
				my_pixel_put(t->im, set_color(pow(set.res, t->depth_r),
						pow(set.res, t->depth_g), pow(set.res, t->depth_b)),
						x + set.x_split, set.y_coord);
			else
				my_pixel_put(t->im, set.def, x + set.x_split, set.y_coord);
		}
	}
}

static void		*put(void *arg)
{
	t_terrain	*t;

	t = (t_terrain *)arg;
	if (t->fractal == ONE)
		t->checker = in_mandelbrot;
	else if (t->fractal == TWO)
		t->checker = in_julia;
	else if (t->fractal == THREE)
		t->checker = in_mandelbrot3;
	else if (t->fractal == FOUR)
		t->checker = in_julia3;
	else if (t->fractal == FIVE)
		t->checker = in_ship;
	else if (t->fractal == SIX)
		t->checker = in_mandelbrot4;
	else if (t->fractal == SEVEN)
		t->checker = in_julia4;
	else if (t->fractal == EIGHT)
		t->checker = in_mandelbrot5;
	do_put(t);
	return (NULL);
}

void			set_default(t_terrain *t)
{
	t->im.opacity = 0;
	t->z = 400;
	t->iter = 100;
	t->depth_r = 2;
	t->depth_g = 2;
	t->depth_b = 2;
	t->x_abs = (t->fractal == ONE || t->fractal == FIVE) ?
		100 : 0;
	t->y_abs = (t->fractal == FIVE) ? 200 : 0;
	t->x_old = 0;
	t->y_old = 0;
	t->animation = 0;
	t->move = 0;
	t->zoom = 0;
	t->julia_arg.re = -0.55;
	t->julia_arg.im = -0.55;
	t->do_iter = 0;
	t->julia_an = 0;
	t->julia_freeze = 0;
	t->do_iter = 0;
	put_fractol(t);
}

void			put_fractol(t_terrain *t)
{
	t_terrain	ts[THREADS];
	int			i;
	int			start;
	int			step;
	int			until;

	mlx_clear_window(t->e.mlx, t->e.win);
	i = -1;
	start = 0;
	step = WIDTH / THREADS;
	until = step;
	while (++i < THREADS)
	{
		ts[i] = *t;
		ts[i].x_start = start;
		start += step - 1;
		ts[i].x_until = until;
		until += step;
		pthread_create(&ts[i].pth, NULL, put, &ts[i]);
	}
	while (--i >= 0)
		pthread_join(ts[i].pth, NULL);
	mlx_put_image_to_window(t->e.mlx, t->e.win, t->im.ptr, 0, 0);
}
