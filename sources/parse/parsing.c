/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   specialize.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qcharpen <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/27 15:09:16 by qcharpen     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/17 14:39:41 by qcharpen    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/parse.h"

t_flags		*parse(char *arg)
{
	t_flags		*spec;

	if ((spec = (t_flags*)ft_memalloc(sizeof(*spec))) == NULL)
		return (NULL);
	set_t_flags(spec);
	while (!is_conv(*arg) && (*arg))
	{
		if (is_flag(*arg))
			def_flags(*arg, spec);
		else if (ft_isdigit(*arg))
			spec->width = mini_atoi(&arg);
		else if (*arg == '.')
		{
			arg++;
			spec->prec = 0;
			spec->prec = mini_atoi(&arg);
		}
		else if (is_size(*arg))
			def_size(&arg, spec);
		arg++;
	}
	if (!(*arg))
		return (NULL);
	spec->conv = *arg;
	return (spec);
}

void		set_t_flags(t_flags *spec)
{
	spec->flags[0] = 0;
	spec->flags[1] = 0;
	spec->flags[2] = 0;
	spec->flags[3] = 0;
	spec->flags[4] = 0;
	spec->flags[5] = 0;
	spec->width = -1;
	spec->prec = -1;
	spec->size = 0;
	spec->conv = '0';
}

void		def_flags(char c, t_flags *spec)
{
	if (c == '#')
		spec->flags[hash] = 1;
	if (c == '0')
		spec->flags[zero] = 1;
	if (c == '-')
		spec->flags[minus] = 1;
	if (c == '+')
		spec->flags[plus] = 1;
	if (c == ' ')
		spec->flags[space] = 1;
	if (c == 'L')
		spec->flags[maj_l] = 1;
}

int			mini_atoi(char **arg)
{
	int		rst;

	rst = 0;
	while (ft_isdigit(**arg))
	{
		rst *= 10;
		rst += **arg - '0';
		(*arg)++;
	}
	(*arg)--;
	return (rst);
}

void		def_size(char **arg, t_flags *spec)
{
	if (**arg == 'h' && spec->size <= hh)
	{
		spec->size = h;
		if (*(*arg + 1) == 'h')
		{
			(*arg)++;
			spec->size = hh;
		}
	}
	else if (**arg == 'l' && spec->size <= ll)
	{
		spec->size = l;
		if (*(*arg + 1) == 'l')
		{
			(*arg)++;
			spec->size = ll;
		}
	}
	else if (**arg == 'j' && spec->size <= j)
		spec->size = j;
	else if (**arg == 'z')
		spec->size = z;
}
