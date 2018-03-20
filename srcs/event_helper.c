/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 17:37:57 by vkovsh            #+#    #+#             */
/*   Updated: 2018/01/26 17:14:02 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_exit(t_env *e, void *ptr)
{
	mlx_destroy_image(e->mlx, ptr);
	mlx_destroy_window(e->mlx, e->win);
	exit(0);
}

void	change_fractal(int k, t_terrain *t)
{
	t->fractal = k;
	set_default(t);
}

void	ft_animation(t_terrain *t)
{
	if (t->animation)
	{
		t->depth_r = t->depth_r >= 10 ? 1 : t->depth_r + 1;
		t->depth_g = t->depth_g >= 10 ? 1 : t->depth_g + 2;
		t->depth_b = t->depth_b >= 10 ? 1 : t->depth_b + 3;
	}
}

int		loop_check(t_terrain *t)
{
	int	check;

	check = t->move == RIGHT || t->move == LEFT ||
		t->move == DOWN || t->move == UP ||
		t->zoom || t->do_iter || t->animation
		|| t->julia_an || t->do_opacity;
	return (check);
}

void	ft_julia_an(t_terrain *t)
{
	if (t->fractal == TWO || t->fractal == FOUR || t->fractal == SEVEN)
		if (t->julia_an)
		{
			if (t->julia_arg.re >= 1 && t->julia_arg.im <= -1)
			{
				t->julia_arg.re = -1;
				t->julia_arg.im = 1;
			}
			else
			{
				t->julia_arg.re += 0.1;
				t->julia_arg.im -= 0.1;
			}
		}
}
