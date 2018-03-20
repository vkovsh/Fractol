/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 17:35:27 by vkovsh            #+#    #+#             */
/*   Updated: 2018/01/28 15:20:26 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	key_hook(int k, t_terrain *t)
{
	if (k == ESC)
		my_exit(&t->e, t->im.ptr);
	else if (COL(k))
		change_depth(k, t);
	else if (k == PLUS || k == MIN)
		t->zoom = 0;
	else if (ARR(k))
		t->move = 0;
	else if (k == ITER_P || k == ITER_M)
		t->do_iter = 0;
	else if (k == Q)
		set_default(t);
	else if (k == OP_M || k == OP_P)
		t->do_opacity = 0;
	else if (NU(k))
		change_fractal(k, t);
	else if (k == A)
		t->animation = t->animation ? 0 : 1;
	else if (k == J)
		t->julia_an = t->julia_an ? 0 : 1;
	else if (k == S)
		t->julia_freeze = t->julia_freeze ? 0 : 1;
	return (0);
}

int	mouse_hook(int k, int x, int y, t_terrain *t)
{
	if (k == 1)
	{
		if (t->fractal == TWO || t->fractal == FOUR || t->fractal == SEVEN)
		{
			t->julia_arg.re = (x - H_WIDTH) / (double)H_WIDTH;
			t->julia_arg.im = (-y + H_HEIGHT) / (double)H_HEIGHT;
			put_fractol(t);
		}
	}
	else if (k == WHEEL_P && 1 / t->z > 0.0000000001)
	{
		t->z *= 1.1;
		t->x_abs -= 0.1 * (x - H_WIDTH - t->x_abs);
		t->y_abs -= 0.1 * (y - H_HEIGHT - t->y_abs);
		put_fractol(t);
	}
	else if (k == WHEEL_M)
	{
		t->z *= 0.9;
		t->x_abs += 0.1 * (x - H_WIDTH - t->x_abs);
		t->y_abs += 0.1 * (y - H_HEIGHT - t->y_abs);
		put_fractol(t);
	}
	return (0);
}

int	loop_hook(t_terrain *t)
{
	if (loop_check(t))
	{
		ft_animation(t);
		t->im.opacity += 25 * t->do_opacity;
		if (t->move == RIGHT)
			t->x_abs += 50;
		else if (t->move == LEFT)
			t->x_abs -= 50;
		else if (t->move == UP)
			t->y_abs -= 50;
		else if (t->move == DOWN)
			t->y_abs += 50;
		if (t->zoom == -1)
			t->z /= 1.1;
		else if (t->zoom == 1)
			t->z *= 1.1;
		ft_julia_an(t);
		t->iter += 5 * t->do_iter;
		put_fractol(t);
	}
	return (0);
}

int	key_release(int k, t_terrain *t)
{
	if (k == RIGHT)
		t->move = RIGHT;
	else if (k == LEFT)
		t->move = LEFT;
	else if (k == UP)
		t->move = UP;
	else if (k == DOWN)
		t->move = DOWN;
	else if (k == PLUS)
		t->zoom = 1;
	else if (k == MIN)
		t->zoom = -1;
	else if (k == ITER_P)
		t->do_iter = 1;
	else if (k == ITER_M)
		t->do_iter = -1;
	else if (k == OP_M)
		t->do_opacity = -1;
	else if (k == OP_P)
		t->do_opacity = 1;
	return (0);
}

int	mouse_move(int x, int y, t_terrain *t)
{
	if (!t->julia_freeze)
		if (t->fractal == TWO || t->fractal == FOUR || t->fractal == SEVEN)
		{
			t->julia_arg.re = (x - H_WIDTH) / (double)H_WIDTH;
			t->julia_arg.im = (-y + H_HEIGHT) / (double)H_HEIGHT;
			put_fractol(t);
		}
	return (0);
}
