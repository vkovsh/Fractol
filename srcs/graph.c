/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkovsh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 17:50:32 by vkovsh            #+#    #+#             */
/*   Updated: 2018/01/23 12:45:17 by vkovsh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				my_pixel_put(t_image im, t_color color, int x, int y)
{
	unsigned char	*split;

	split = im.begin + y * im.len + x * 4;
	*split++ = color.b;
	*split++ = color.g;
	*split++ = color.r;
	*split = im.opacity;
}

t_color				set_color(int r, int g, int b)
{
	t_color			color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}

void				change_depth(int k, t_terrain *t)
{
	if (k == R)
		t->depth_r += (t->depth_r < 10) ? 1 : 0;
	else if (k == E)
		t->depth_r -= (t->depth_r > 0) ? 1 : 0;
	else if (k == G)
		t->depth_g += (t->depth_g < 10) ? 1 : 0;
	else if (k == F)
		t->depth_g -= (t->depth_g > 0) ? 1 : 0;
	else if (k == B)
		t->depth_b += (t->depth_b < 10) ? 1 : 0;
	else if (k == V)
		t->depth_b -= (t->depth_b > 0) ? 1 : 0;
	put_fractol(t);
}
