/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qcharpen <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/27 13:02:54 by qcharpen     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/12 07:33:01 by gmadec      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <errno.h>
# include "parse.h"
# include "libft.h"
# include "lists.h"
# include "handlers.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define MAX(a, b) ((a > b) ? a : b)
# define MIN(a, b) ((a > b) ? b : a)
# define ABS(a) (a > 0 ? a : -a)

int				ft_printf(const char *format, ...);
int				ft_dprintf(int fd, const char *format, ...);
int				ft_sprintf(char **str, const char *format, ...);
int				ft_fprintf(char *str, const char *format, ...);
int				ft_inner_printf(int (*f)(void**, t_list*), void **fd,
		va_list args, const char *format);

#endif
