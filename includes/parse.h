/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   flags.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qcharpen <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/05 18:26:25 by qcharpen     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/17 14:39:20 by qcharpen    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H
# include "ft_printf.h"

enum			e_flags {hash, zero, minus, plus, space, maj_l};
enum			e_size {none, hh, h, l, ll, j, z};

typedef struct	s_flags {
	int			flags[6];
	int			width;
	int			prec;
	int			size;
	char		conv;
}				t_flags;

t_flags			*parse(char *arg);
void			set_t_flags(t_flags *spec);
void			def_flags(char c, t_flags *spec);
int				mini_atoi(char **arg);
void			def_size(char **arg, t_flags *spec);

int				is_conv(const char c);
int				is_size(const char c);
int				is_flag(const char c);
int				is_valid(const char c);

#endif
