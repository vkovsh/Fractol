/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 13:19:11 by vkovsh            #+#    #+#             */
/*   Updated: 2018/01/28 15:28:24 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "mlx.h"
# include <math.h>
# include "libft.h"
# include <stdlib.h>
# include <pthread.h>
# define WIDTH 1520
# define HEIGHT 1080
# define H_WIDTH 760
# define H_HEIGHT 540
# define ESC 53
# define R 15
# define E 14
# define G 5
# define F 3
# define B 11
# define V 9
# define PLUS 69
# define MIN 78
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define ITER_P 116
# define ITER_M 121
# define Q 12
# define OP_M 43
# define OP_P 47
# define A 0
# define THREADS 6
# define ONE 18
# define TWO 19
# define THREE 20
# define FOUR 21
# define FIVE 23
# define SIX 22
# define SEVEN 26
# define EIGHT 28
# define POW2(x) (x * x)
# define POW3(x) x * POW2(x)
# define POW4(x) x * POW3(x)
# define POW5(x) x * POW4(x)
# define J 38
# define S 1
# define WHEEL_P 5
# define WHEEL_M 4
# define COL(k) k == R || k == E || k == G || k == F || k == B || k == V
# define ARR(k) k == RIGHT || k == LEFT || k == UP || k == DOWN
# define NU1(k) k == ONE || k == TWO || k == THREE || k == FOUR
# define NU2(k) k == FIVE || k == SIX || k == SEVEN || k == EIGHT
# define NU(k) NU1(k) || NU2(k)

typedef struct		s_color
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}					t_color;

typedef struct		s_set
{
	int				y_coord;
	int				y_max;
	int				x_max;
	int				y_split;
	int				x_split;
	double			step;
	int				res;
	int				y;
	struct s_color	def;
}					t_set;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
}					t_env;

typedef struct		s_image
{
	void			*ptr;
	int				bpp;
	int				len;
	int				end;
	unsigned char	opacity;
	void			*begin;
}					t_image;

typedef struct		s_complex
{
	double			re;
	double			im;
}					t_complex;

typedef struct		s_terrain
{
	int				fractal;
	int				x_old;
	int				y_old;
	int				x_start;
	int				x_until;
	struct s_env	e;
	struct s_image	im;
	double			z;
	pthread_t		pth;
	int				depth_r;
	int				depth_g;
	int				depth_b;
	int				iter;
	double			x_abs;
	double			y_abs;
	int				animation;
	t_complex		julia_arg;
	int				move;
	int				zoom;
	int				do_iter;
	int				julia_an;
	int				julia_freeze;
	int				do_opacity;
	int				(*checker)(t_complex, struct s_terrain *);
}					t_terrain;

void				put_fractol(t_terrain *t);
void				my_pixel_put(t_image im, t_color color, int x, int y);
t_color				set_color(int r, int g, int b);
void				change_depth(int k, t_terrain *t);
void				set_default(t_terrain *t);
int					in_mandelbrot(t_complex c, t_terrain *t);
int					in_mandelbrot3(t_complex c, t_terrain *t);
int					in_mandelbrot4(t_complex c, t_terrain *t);
int					in_mandelbrot5(t_complex c, t_terrain *t);
int					in_julia(t_complex c, t_terrain *t);
int					in_julia3(t_complex c, t_terrain *t);
int					in_julia4(t_complex c, t_terrain *t);
int					in_ship(t_complex c, t_terrain *t);
int					key_hook(int k, t_terrain *t);
int					mouse_hook(int k, int x, int y, t_terrain *t);
int					loop_hook(t_terrain *t);
int					key_release(int k, t_terrain *t);
int					mouse_move(int x, int y, t_terrain *t);
void				my_exit(t_env *e, void *ptr);
void				change_fractal(int k, t_terrain *t);
void				ft_animation(t_terrain *t);
int					loop_check(t_terrain *t);
void				ft_julia_an(t_terrain *t);
#endif
