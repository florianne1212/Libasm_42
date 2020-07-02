/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcoudert <fcoudert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 22:05:16 by user42            #+#    #+#             */
/*   Updated: 2020/06/18 15:09:21 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <stdlib.h>

extern int		ft_strlen(char *test);
extern ssize_t	ft_write(int fd, const void *buf, size_t count);
extern char		*ft_strdup(const char *test);
extern char		*ft_strcpy(char *dest, char *src);
extern int		ft_strcmp(char *s1, char *s2);
extern ssize_t	ft_read(int fd, const void *buf, size_t count);

void			test_int(int a, int b);
void			cmp_char(char *s1, char *s2);
void			test_sign(int a, int b);
void			clear_s1(char *s1);
void			test_strlen(void);
void			test_strdup(void);
void			test_strcpy(void);
void			test_strcmp(void);
void			test_error_write(void);
void			cmp_char_free(char *s1, char *s2);

#endif
