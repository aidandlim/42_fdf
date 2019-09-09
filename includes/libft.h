/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlim <dlim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 00:38:37 by dlim              #+#    #+#             */
/*   Updated: 2019/06/23 18:10:25 by dlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include "fcntl.h"
# include "unistd.h"
# include "stdlib.h"
# include "string.h"

int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_isenter(char c);
int		ft_isspace(char c);
int		ft_getlargerstrlen(char const *s1, char const *s2);
int		ft_getwordlen(char const *str, char c);
int		ft_getwordscount(char const *str, char c);
void	ft_memdel(void **ap);
void	*ft_memset(void *b, int c, size_t len);
void	ft_putchar_fd(char c, int fd);
void	ft_putchar(char c);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putstr(char const *s);
char	*ft_strchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_strdel(char **as);
char	*ft_strdup(const char *s1);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strncpy(char *dst, const char *src, size_t len);
char	*ft_strnew(size_t size);
char	**ft_strsplit(char const *s, char c);

#endif
