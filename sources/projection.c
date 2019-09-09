/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim <dlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 21:41:44 by dlim              #+#    #+#             */
/*   Updated: 2019/06/26 14:23:43 by dlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_fdf_projection_parallel(t_param p, int *points)
{
	p.d.x1 = p.g.mx + p.d.i2 * p.g.s1;
	p.d.y1 = p.g.my + (p.d.i1 - 1) * p.g.s1;
	p.d.x2 = p.g.mx + (p.d.i2 + 1) * p.g.s1;
	p.d.y2 = p.g.my + (p.d.i1 - 1) * p.g.s1;
	p.d.i1 == 1 ? ft_fdf_draw_line(p, points[0], points[1]) : NULL;
	p.d.x1 = p.g.mx + p.d.i2 * p.g.s1;
	p.d.y1 = p.g.my + p.d.i1 * p.g.s1;
	p.d.x2 = p.g.mx + p.d.i2 * p.g.s1;
	p.d.y2 = p.g.my + (p.d.i1 - 1) * p.g.s1;
	p.d.i2 == 0 ? ft_fdf_draw_line(p, points[3], points[0]) : NULL;
	p.d.x1 = p.g.mx + (p.d.i2 + 1) * p.g.s1;
	p.d.y1 = p.g.my + (p.d.i1 - 1) * p.g.s1;
	p.d.x2 = p.g.mx + (p.d.i2 + 1) * p.g.s1;
	p.d.y2 = p.g.my + p.d.i1 * p.g.s1;
	ft_fdf_draw_line(p, points[1], points[2]);
	p.d.x1 = p.g.mx + (p.d.i2 + 1) * p.g.s1;
	p.d.y1 = p.g.my + p.d.i1 * p.g.s1;
	p.d.x2 = p.g.mx + p.d.i2 * p.g.s1;
	p.d.y2 = p.g.my + p.d.i1 * p.g.s1;
	ft_fdf_draw_line(p, points[2], points[3]);
}

void	ft_fdf_projection_iso(t_param p, int *points)
{
	p.d.x1 = p.g.mx + p.d.i1 * p.g.s1 + p.d.i2 * p.g.s1;
	p.d.y1 = ft_fdf_projection_get_value(0, p, points[0]);
	p.d.x2 = p.g.mx + p.d.i1 * p.g.s1 + p.d.i2 * p.g.s1 + p.g.s1;
	p.d.y2 = ft_fdf_projection_get_value(1, p, points[1]);
	p.d.i1 == 1 ? ft_fdf_draw_line(p, points[0], points[1]) : NULL;
	p.d.x1 = p.g.mx + p.d.i1 * p.g.s1 + p.d.i2 * p.g.s1 + p.g.s1;
	p.d.y1 = ft_fdf_projection_get_value(3, p, points[3]);
	p.d.x2 = p.g.mx + p.d.i1 * p.g.s1 + p.d.i2 * p.g.s1;
	p.d.y2 = ft_fdf_projection_get_value(0, p, points[0]);
	p.d.i2 == 0 ? ft_fdf_draw_line(p, points[3], points[0]) : NULL;
	p.d.x1 = p.g.mx + p.d.i1 * p.g.s1 + p.d.i2 * p.g.s1 + p.g.s1;
	p.d.y1 = ft_fdf_projection_get_value(1, p, points[1]);
	p.d.x2 = p.g.mx + p.d.i1 * p.g.s1 + p.d.i2 * p.g.s1 + p.g.s1 * 2;
	p.d.y2 = ft_fdf_projection_get_value(2, p, points[2]);
	ft_fdf_draw_line(p, points[1], points[2]);
	p.d.x1 = p.g.mx + p.d.i1 * p.g.s1 + p.d.i2 * p.g.s1 + p.g.s1 * 2;
	p.d.y1 = ft_fdf_projection_get_value(2, p, points[2]);
	p.d.x2 = p.g.mx + p.d.i1 * p.g.s1 + p.d.i2 * p.g.s1 + p.g.s1;
	p.d.y2 = ft_fdf_projection_get_value(3, p, points[3]);
	ft_fdf_draw_line(p, points[2], points[3]);
}

double	ft_fdf_projection_get_value(int num, t_param p, int value)
{
	double result;

	if (num == 0)
	{
		result = p.g.my + p.d.i1 * p.g.s1 / 2 - p.d.i2 * p.g.s1 / 2
			- value * p.g.s2;
	}
	if (num == 1)
	{
		result = p.g.my + p.d.i1 * p.g.s1 / 2 - p.d.i2 * p.g.s1 / 2
			- p.g.s1 / 2 - value * p.g.s2;
	}
	if (num == 2)
	{
		result = p.g.my + p.d.i1 * p.g.s1 / 2 - p.d.i2 * p.g.s1 / 2
			- value * p.g.s2;
	}
	if (num == 3)
	{
		result = p.g.my + p.d.i1 * p.g.s1 / 2 - p.d.i2 * p.g.s1 / 2
			+ p.g.s1 / 2 - value * p.g.s2;
	}
	return (result);
}
