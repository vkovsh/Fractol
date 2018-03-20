/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 14:10:15 by vkovsh            #+#    #+#             */
/*   Updated: 2018/01/28 15:17:50 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		set_fractal(char c)
{
	if (c < 53)
		return (c - 31);
	else if (c == 53)
		return (FIVE);
	else if (c == 55)
		return (SEVEN);
	else if (c == 56)
		return (EIGHT);
	return (SIX);
}

static void		set_graph(t_terrain *t, char c)
{
	t->e.mlx = mlx_init();
	t->e.win = mlx_new_window(t->e.mlx, WIDTH, HEIGHT, "FRACTOL");
	t->im.ptr = mlx_new_image(t->e.mlx, WIDTH, HEIGHT);
	t->im.bpp = 4;
	t->im.len = WIDTH;
	t->im.opacity = 0;
	t->im.begin = mlx_get_data_addr(t->im.ptr,
			&t->im.bpp, &t->im.len, &t->im.end);
	t->fractal = set_fractal(c);
	set_default(t);
	put_fractol(t);
	mlx_mouse_hook(t->e.win, &mouse_hook, t);
	mlx_key_hook(t->e.win, &key_hook, t);
	mlx_hook(t->e.win, 2, 1L << 0, &key_release, t);
	mlx_hook(t->e.win, 6, 1L << 6, &mouse_move, t);
	mlx_loop_hook(t->e.mlx, &loop_hook, t);
	mlx_loop(t->e.mlx);
}

static void		force_exit(void)
{
	ft_putendl("Usage: ./fractol [<f_id>]");
	ft_putendl("f_id's list:");
	ft_putendl("1 - Mandelbrot");
	ft_putendl("2 - Julia");
	ft_putendl("3 - Mandelbrot3");
	ft_putendl("4 - Julia3");
	ft_putendl("5 - Burning Ship");
	ft_putendl("6 - Mandelbrot4");
	ft_putendl("7 - Julia4");
	ft_putendl("8 - Mandelbrot5");
	exit(0);
}

int				main(int ac, char **av)
{
	t_terrain	t;

	if (ac == 2)
	{
		if (ft_strlen(av[1]) == 1 &&
				*av[1] >= 49 && *av[1] <= 56)
			set_graph(&t, *av[1]);
		else
			force_exit();
	}
	else
		force_exit();
	return (0);
}
