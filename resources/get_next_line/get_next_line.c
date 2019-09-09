/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim <dlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 20:13:21 by dlim              #+#    #+#             */
/*   Updated: 2019/06/26 17:14:30 by dlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_verify_endl(char **s, char **line, int fd)
{
	*line = ft_strdup(s[fd]);
	ft_strdel(&s[fd]);
}

void	ft_verify_newl(char **s, char **line, int fd, int i)
{
	char		*t;

	*line = ft_strsub(s[fd], 0, i);
	t = ft_strdup(s[fd] + i + 1);
	free(s[fd]);
	s[fd] = t;
	if (s[fd][0] == '\0')
		ft_strdel(&s[fd]);
}

int		ft_verify_core(char **s, char **line, int fd, int r)
{
	int			i;

	i = 0;
	while (s[fd][i] != '\n' && s[fd][i] != '\0')
		i++;
	if (s[fd][i] == '\n')
	{
		ft_verify_newl(s, line, fd, i);
	}
	else if (s[fd][i] == '\0')
	{
		if (r == BUFF_SIZE)
			return (0);
		ft_verify_endl(s, line, fd);
	}
	return (1);
}

int		ft_read_loop(char **s, int fd, int r)
{
	char		*b;
	char		*t;

	b = ft_strnew(BUFF_SIZE);
	while ((r = read(fd, b, BUFF_SIZE)) > 0)
	{
		b[r] = '\0';
		if (s[fd] == NULL)
			s[fd] = ft_strnew(1);
		t = ft_strjoin(s[fd], b);
		s[fd] = t;
		if (ft_strchr(b, '\n'))
			break ;
	}
	free(b);
	return (r);
}

int		get_next_line(const int fd, char **line)
{
	static char	*s[FD_SIZE];
	int			r;

	r = 0;
	if (FD_SIZE < fd || fd < 0 || line == NULL)
		return (-1);
	r = ft_read_loop(s, fd, r);
	if (r < 0)
		return (-1);
	if (r == 0 && (s[fd] == NULL || s[fd][0] == '\0'))
		return (0);
	if (!ft_verify_core(s, line, fd, r))
		get_next_line(fd, line);
	return (1);
}
