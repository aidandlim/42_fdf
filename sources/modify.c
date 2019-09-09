/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim <dlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 00:29:25 by dlim              #+#    #+#             */
/*   Updated: 2019/06/25 00:31:25 by dlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_param		ft_fdf_modify_core(t_param p, int k)
{
	if (k == 49)
		p.g = ft_fdf_modify_pj(p.g);
	if (k == 0 || k == 1 || k == 2 || k == 13)
		p.g = ft_fdf_modify_move(p.g, k);
	if (k == 12 || k == 14 || k == 6 || k == 8)
		p.g = ft_fdf_modify_size(p.g, k);
	if (k == 36)
		p.g = ft_fdf_modify_init(p.g);
	mlx_clear_window(p.i.m, p.i.w);
	return (p);
}

t_global	ft_fdf_modify_pj(t_global g)
{
	if (g.pj)
	{
		g.pj = 0;
		g.mx = 50;
		g.my = 50;
	}
	else
	{
		g.pj = 1;
		g.mx = 50;
		g.my = 666;
	}
	return (g);
}

t_global	ft_fdf_modify_move(t_global g, int k)
{
	if (k == 0)
		g.mx = g.mx - 30;
	if (k == 2)
		g.mx = g.mx + 30;
	if (k == 13)
		g.my = g.my - 30;
	if (k == 1)
		g.my = g.my + 30;
	return (g);
}

t_global	ft_fdf_modify_size(t_global g, int k)
{
	if (k == 14)
		g.s1 += 2.5;
	if (k == 12)
		g.s1 > 2.5 ? g.s1 -= 2.5 : g.s1;
	if (k == 8)
		g.s2 += 3;
	if (k == 6)
		g.s2 -= 3;
	return (g);
}

t_global	ft_fdf_modify_init(t_global g)
{
	g.pj = 0;
	g.mx = 50;
	g.my = 50;
	g.s1 = 30;
	g.s2 = 10;
	return (g);
}
