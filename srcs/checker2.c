/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 15:22:35 by vkovsh            #+#    #+#             */
/*   Updated: 2018/01/28 15:25:33 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int				in_mandelbrot5(t_complex c, t_terrain *t)
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
		n.re = POW5(o.re) - 10 * POW3(o.re) * POW2(o.im) +
			5 * o.re * POW4(o.im) + c.re;
		n.im = 5 * POW4(o.re) * o.im - 10 * POW2(o.re) * POW3(o.im) +
			POW5(o.im) + c.im;
	}
	return (iter - 1);
}

int				in_julia4(t_complex z, t_terrain *t)
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
		z.re = POW4(o.re) - 6 * POW2(o.re) * POW2(o.im) +
			POW4(o.im) + c.re;
		z.im = 4 * POW3(o.re) * o.im - 4 * o.re * POW3(o.im)
			+ c.im;
	}
	return (iter - 1);
}

int				in_ship(t_complex c, t_terrain *t)
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
		if (o.re < 0)
			o.re *= -1;
		if (o.im < 0)
			o.im *= -1;
		n.re = o.re * o.re - o.im * o.im + c.re;
		n.im = 2 * o.re * o.im + c.im;
	}
	return (iter - 1);
}
