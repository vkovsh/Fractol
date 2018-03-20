/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 12:50:15 by vkovsh            #+#    #+#             */
/*   Updated: 2018/01/28 15:25:11 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				in_julia(t_complex z, t_terrain *t)
{
	t_complex	o;
	t_complex	c;
	int			iter;

	c.re = t->julia_arg.re;
	c.im = t->julia_arg.re;
	iter = 0;
	while (iter++ < t->iter && z.re * z.re + z.im * z.im <= 4)
	{
		o = z;
		z.re = o.re * o.re - o.im * o.im + c.re;
		z.im = 2 * o.re * o.im + c.im;
	}
	return (iter - 1);
}

int				in_julia3(t_complex z, t_terrain *t)
{
	t_complex	o;
	t_complex	c;
	int			iter;

	c.re = t->julia_arg.re;
	c.im = t->julia_arg.im;
	iter = 0;
	while (iter++ < t->iter && z.re * z.re + z.im * z.im <= 4)
	{
		o = z;
		z.re = POW3(o.re) - 3 * o.re * POW2(o.im) + c.re;
		z.im = 3 * POW2(o.re) * o.im - POW3(o.im) + c.im;
	}
	return (iter - 1);
}

int				in_mandelbrot(t_complex c, t_terrain *t)
{
	t_complex	o;
	t_complex	n;
	int			iter;
	double		tmp;

	tmp = c.re - 0.25;
	if (sqrt(tmp * tmp + c.im * c.im) <
			0.5 - 0.5 * cos(atan2(c.im, tmp)))
		return (t->iter);
	o.re = 0;
	o.im = 0;
	n = o;
	iter = 0;
	while (iter++ < t->iter && n.re * n.re + n.im * n.im <= 4)
	{
		o = n;
		n.re = o.re * o.re - o.im * o.im + c.re;
		n.im = 2 * o.re * o.im + c.im;
	}
	return (iter - 1);
}

int				in_mandelbrot3(t_complex c, t_terrain *t)
{
	t_complex	o;
	t_complex	n;
	int			iter;

	o.re = 0;
	o.im = 0;
	n = o;
	iter = 0;
	while (iter++ < t->iter && n.re * n.re + n.im * n.im <= 4)
	{
		o = n;
		n.re = POW3(o.re) - 3 * o.re * POW2(o.im) + c.re;
		n.im = 3 * POW2(o.re) * o.im - POW3(o.im) + c.im;
	}
	return (iter - 1);
}

int				in_mandelbrot4(t_complex c, t_terrain *t)
{
	t_complex	o;
	t_complex	n;
	int			iter;

	o.re = 0;
	o.im = 0;
	n = o;
	iter = 0;
	while (iter++ < t->iter && n.re * n.re + n.im * n.im <= 4)
	{
		o = n;
		n.re = POW4(o.re) - 6 * POW2(o.re) * POW2(o.im) +
			POW4(o.im) + c.re;
		n.im = 4 * POW3(o.re) * o.im - 4 * o.re * POW3(o.im)
			+ c.im;
	}
	return (iter - 1);
}
