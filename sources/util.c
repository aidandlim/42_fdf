/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim <dlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 19:57:06 by dlim              #+#    #+#             */
/*   Updated: 2019/06/26 17:12:56 by dlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_fdf_util_get_color(t_param p, int a, int b, double progress)
{
	int	value;

	if (a != 0)
		a = a * p.g.s2;
	if (b != 0)
		b = b * p.g.s2;
	value = 0;
	if (a == b)
		value = a;
	else
	{
		if (a < b)
			value = a + (b - a) * progress;
		else
			value = b + (a - b) * (1 - progress);
	}
	return (ft_fdf_util_get_color_value(value));
}

int		ft_fdf_util_get_color_value(int value)
{
	if (value <= -180)
		return (0x673AB7);
	else if (value <= -150)
		return (0x3F51B5);
	else if (value <= -120)
		return (0x2196F3);
	else if (value <= -90)
		return (0x03A9F4);
	else if (value <= -60)
		return (0x00BCD4);
	else if (value <= -30)
		return (0x009688);
	else if (value <= 0)
		return (0x4CAF50);
	else if (value <= 30)
		return (0xFFEB3B);
	else if (value <= 60)
		return (0xFFC107);
	else if (value <= 90)
		return (0xFF9800);
	else if (value <= 120)
		return (0xFF5722);
	else if (value <= 150)
		return (0xF44336);
	return (0xE91E63);
}

void	ft_fdf_util_free(char **s)
{
	int i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
}

int		ft_fdf_key(int keycode)
{
	if (keycode == 53)
		ft_fdf_exit();
	if (keycode == 0 || keycode == 1 || keycode == 2 || keycode == 6 ||
		keycode == 8 || keycode == 12 || keycode == 13 || keycode == 14 ||
		keycode == 36 || keycode == 49)
		ft_fdf(0, keycode);
	return (0);
}

void	ft_fdf_exit(void)
{
	ft_putstr("Good bye!\n");
	exit(0);
}
