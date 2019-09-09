/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim <dlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/16 23:36:49 by dlim              #+#    #+#             */
/*   Updated: 2019/06/26 14:23:06 by dlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include "get_next_line.h"
# include "../resources/minilibx_macos/mlx.h"
# include "math.h"
# define WIN_X 1000
# define WIN_Y 1035
# define TITLE "42 FDF Project by @dlim"
# define PRG1(x, y1, y2)((x - y1) / (y2 - y1));
# define PRG2(x, x1, x2)((x - x1) / (x2 - x1));

typedef struct	s_info {
	void		*m;
	void		*w;
	int			fd;
	char		*file;
}				t_info;

typedef struct	s_global {
	int			pj;
	double		mx;
	double		my;
	double		s1;
	double		s2;
}				t_global;

typedef struct	s_draw {
	int			i1;
	int			i2;
	double		x1;
	double		y1;
	double		x2;
	double		y2;
}				t_draw;

typedef struct	s_param {
	t_info		i;
	t_global	g;
	t_draw		d;
}				t_param;

void			ft_fdf(char *file, int keycode);
t_param			ft_fdf_file(t_param p, char *file);
t_param			ft_fdf_init(t_param p);
void			ft_fdf_manual(t_param p);
void			ft_fdf_run(t_param p);
t_param			ft_fdf_modify_core(t_param p, int k);
t_global		ft_fdf_modify_pj(t_global g);
t_global		ft_fdf_modify_move(t_global g, int k);
t_global		ft_fdf_modify_size(t_global g, int k);
t_global		ft_fdf_modify_init(t_global g);
void			ft_fdf_draw_get_line(t_param p);
void			ft_fdf_draw_set_point(t_param p, char *before, char *this);
void			ft_fdf_draw_line(t_param p, int init, int end);
void			ft_fdf_draw_line_horizontal(t_param p, int init, int end);
void			ft_fdf_draw_line_other(t_param p, int init, int end);
void			ft_fdf_projection_parallel(t_param p, int *points);
void			ft_fdf_projection_iso(t_param p, int *points);
double			ft_fdf_projection_get_value(int num, t_param p, int value);
int				ft_fdf_util_get_color(t_param p, int a, int b, double progress);
int				ft_fdf_util_get_color_value(int value);
void			ft_fdf_util_free(char **s);
int				ft_fdf_key(int keycode);
void			ft_fdf_exit();

#endif
