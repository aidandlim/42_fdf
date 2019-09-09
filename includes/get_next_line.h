/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim <dlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 20:13:29 by dlim              #+#    #+#             */
/*   Updated: 2019/06/26 14:39:34 by dlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 42
# define FD_SIZE 4864

# include "libft.h"

void	ft_verify_endl(char **s, char **line, int fd);
void	ft_verify_newl(char **s, char **line, int fd, int i);
int		ft_verify_core(char **s, char **line, int fd, int r);
int		ft_read_loop(char **s, int fd, int r);
int		get_next_line(const int fd, char **line);

#endif
