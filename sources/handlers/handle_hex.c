/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   handle_int.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qcharpen <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/22 08:26:31 by qcharpen     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/12 07:17:04 by gmadec      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int		is_space(t_flags *spec, char *tmp, intmax_t len, int i)
{
	if (!spec->flags[zero])
		return (i < len - (MAX((int)ft_strlen(tmp),
						spec->prec) + 2 * spec->flags[hash]));
	else
	{
		if (spec->prec == -1)
			return (0);
		else
		{
			if (spec->prec < spec->width)
				return (i < spec->width - MAX(spec->prec, ft_strlen(tmp))
						- 2 * spec->flags[hash]);
			else
				return (0);
		}
	}
}

static int		is_zero(t_flags *spec, char *tmp, intmax_t len, int *i)
{
	if (spec->flags[minus] && ft_strlen(tmp) < spec->prec)
	{
		if (spec->prec > -1)
			return (i[0] < spec->prec - ft_strlen(tmp));
		else
			return (i[0] < spec->flags[hash]);
	}
	else
		return (i[0] < len - (ft_strlen(tmp) - i[1]));
}

static intmax_t	get_arg(t_flags *spec, va_list args)
{
	intmax_t	arg;

	arg = va_arg(args, intmax_t);
	if (spec->size == hh)
		arg = (unsigned char)arg;
	else if (spec->size == h)
		arg = (unsigned short int)arg;
	else if (spec->size == l)
		arg = (unsigned long int)arg;
	else if (spec->size == ll)
		arg = (unsigned long long int)arg;
	else if (spec->size == j)
		arg = (intmax_t)arg;
	else if (spec->size == z)
		arg = (size_t)arg;
	else
		arg = (unsigned int)arg;
	if (arg == 0)
		spec->flags[hash] = 0;
	return (arg);
}

static void		flag_hash(char **rst, int *i, t_flags *spec)
{
	if (spec->flags[hash])
	{
		(*rst)[(*i)++] = '0';
		(*rst)[(*i)++] = spec->conv;
	}
}

t_list			*ftprintf_handle_hex(t_flags *spec, va_list args)
{
	char		*rst;
	char		*tmp;
	intmax_t	arg;
	int			len;
	int			*i;

	arg = get_arg(spec, args);
	if (spec->prec == 0 && arg == 0)
		return (zeroprec(spec));
	tmp = ft_itoa_base_unsigned(arg, 16, spec->conv == 'X');
	len = MAX((int)ft_strlen(tmp) + !(arg == 0) * 2 * spec->flags[hash],
			(MAX(spec->width, spec->prec + 2 * spec->flags[hash])));
	rst = ft_memalloc(sizeof(*rst) * (len + 1));
	i = ft_tabset(2);
	while (is_space(spec, tmp, len, i[0]) && !spec->flags[minus])
		rst[(i[0])++] = ' ';
	flag_hash(&rst, &i[0], spec);
	while (is_zero(spec, tmp, len, i))
		rst[i[0]++] = '0';
	while (tmp[i[1]])
		rst[i[0]++] = tmp[i[1]++];
	while (i[0] < len && spec->flags[minus])
		rst[i[0]++] = ' ';
	ft_printf_utils_norme(&rst, i, tmp);
	return (ft_lstnew(rst, len));
}
