/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim <dlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 23:45:38 by dlim              #+#    #+#             */
/*   Updated: 2019/09/06 18:14:12 by dlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_fdf_run(t_param p)
{
	ft_fdf_manual(p);
	ft_fdf_draw_get_line(p);
	mlx_key_hook(p.i.w, ft_fdf_key, (void *)0);
	mlx_loop(p.i.m);
}

void	ft_fdf_manual(t_param p)
{
	int	a;
	int	b;

	a = WIN_Y - 35;
	while (a < WIN_Y)
	{
		b = 0;
		while (b < WIN_X)
		{
			mlx_pixel_put(p.i.m, p.i.w, b, a, 0x37474F);
			b++;
		}
		a++;
	}
	mlx_string_put(p.i.m, p.i.w, 15, WIN_Y - 30, 0xB0BEC5,
		"Move : WASD    Zoom : Q&E    Height : Z&C    Projection : Space    \
		Reset : Enter    Exit : Escape");
}

t_param	ft_fdf_init(t_param p)
{
	ft_putstr("Welcome to my FdF world!\n");
	p.i.m = mlx_init();
	p.i.w = mlx_new_window(p.i.m, WIN_X, WIN_Y, TITLE);
	p.g.pj = 0;
	p.g.mx = 50;
	p.g.my = 50;
	p.g.s1 = 30;
	p.g.s2 = 10;
	return (p);
}

t_param	ft_fdf_file(t_param p, char *file)
{
	if (file)
		p.i.file = ft_strdup(file);
	p.i.fd = open(p.i.file, O_RDONLY);
	if (p.i.fd == -1)
		ft_putstr("This file is invalid.\n");
	return (p);
}

void	ft_fdf(char *file, int k)
{
	static t_param	p;

	p = ft_fdf_file(p, file);
	if (p.i.fd == -1)
		return ;
	if (k == -1)
		p = ft_fdf_init(p);
	else
		p = ft_fdf_modify_core(p, k);
	ft_fdf_run(p);
}
