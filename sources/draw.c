/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim <dlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 00:35:20 by dlim              #+#    #+#             */
/*   Updated: 2019/06/26 14:59:54 by dlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_fdf_draw_get_line(t_param p)
{
	char	*before;
	char	*this;

	p.d.i1 = 0;
	this = ft_strnew(1);
	while (get_next_line(p.i.fd, &this))
	{
		if (p.d.i1 != 0)
			ft_fdf_draw_set_point(p, before, this);
		before = ft_strdup(this);
		free(this);
		this = ft_strnew(1);
		p.d.i1++;
	}
	if (p.d.i1 == 0)
	{
		ft_putstr("There is no enough map data.\n");
		ft_fdf_exit();
	}
	else
	{
		free(before);
		free(this);
	}
}

void	ft_fdf_draw_set_point(t_param p, char *before, char *this)
{
	char	**b;
	char	**t;
	int		*points;

	b = ft_strsplit(before, ' ');
	t = ft_strsplit(this, ' ');
	p.d.i2 = 0;
	while (b[p.d.i2] && b[p.d.i2 + 1] && t[p.d.i2] && t[p.d.i2 + 1])
	{
		points = (int *)malloc(sizeof(int) * 4);
		points[0] = ft_atoi(b[p.d.i2]);
		points[1] = ft_atoi(b[p.d.i2 + 1]);
		points[2] = ft_atoi(t[p.d.i2 + 1]);
		points[3] = ft_atoi(t[p.d.i2]);
		if (p.g.pj == 0)
			ft_fdf_projection_parallel(p, points);
		else
			ft_fdf_projection_iso(p, points);
		free(points);
		p.d.i2++;
	}
	ft_fdf_util_free(b);
	ft_fdf_util_free(t);
}

void	ft_fdf_draw_line(t_param p, int i, int e)
{
	if (p.d.x1 == p.d.x2)
		ft_fdf_draw_line_horizontal(p, i, e);
	else
		ft_fdf_draw_line_other(p, i, e);
}

void	ft_fdf_draw_line_horizontal(t_param p, int i, int e)
{
	double	x;
	double	prg;

	x = p.d.y1;
	while (p.d.y1 <= p.d.y2 ? x <= p.d.y2 : x >= p.d.y2)
	{
		prg = PRG1(x, p.d.y1, p.d.y2);
		if (x <= WIN_Y - 35 && x >= 0)
			mlx_pixel_put(p.i.m, p.i.w, p.d.x1, x,
				ft_fdf_util_get_color(p, i, e, prg));
		if (p.d.y1 <= p.d.y2)
			x += 0.05;
		else
			x -= 0.05;
	}
}

void	ft_fdf_draw_line_other(t_param p, int i, int e)
{
	double	slope;
	double	x;
	double	y;
	double	prg;

	slope = (p.d.y2 - p.d.y1) / (p.d.x2 - p.d.x1);
	x = p.d.x1;
	y = p.d.y1 - p.d.x1 * slope;
	while (p.d.x1 <= p.d.x2 ? x <= p.d.x2 : x >= p.d.x2)
	{
		prg = PRG2(x, p.d.x1, p.d.x2);
		if (WIN_Y - 35 >= x * slope + y && x * slope + y >= 0)
			mlx_pixel_put(p.i.m, p.i.w, x, x * slope + y,
				ft_fdf_util_get_color(p, i, e, prg));
		if (p.d.x1 <= p.d.x2)
			x += slope > 1.5 || slope < -1.5 ? 0.05 : 1;
		else
			x -= slope > 1.5 || slope < -1.5 ? 0.05 : 1;
	}
}
