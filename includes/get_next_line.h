/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymukobar <ymukobar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/17 03:36:47 by ymukobar          #+#    #+#             */
/*   Updated: 2021/04/26 12:04:54 by ymukobar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# define BUFFER_SIZE 1000

int		get_next_line(int fd, char **line);
int		find_newline(int fd, char **line, char **st_arr, char *buf);
int		read_fd(int fd, char **line, char **st_arr);
size_t	gnl_strchar(char *s, char c);
size_t	gnl_strlen(char *s);
char	*gnl_strnjoin(char *s1, char *s2, size_t na2);
char	*gnl_strdup(char *s1);
int		gnl_free_all(char **line, char **sv, int fd);

#endif
