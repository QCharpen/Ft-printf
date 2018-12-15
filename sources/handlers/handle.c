/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   handle.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qcharpen <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/15 06:53:41 by qcharpen     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/14 07:43:11 by qcharpen    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/handlers.h"

t_list				*handle(char **str, va_list args, int a)
{
	t_flags		*spec;
	int			i;
	t_list		*curr_list;

	i = a;
	while ((*str)[i] && is_valid((*str)[i]) && !is_conv((*str)[i]))
		i++;
	if (!(*str)[i] || !is_conv((*str)[i]))
	{
		*str = &(*str)[i];
		return (ft_lstnew(NULL, -1));
	}
	spec = parse(&(*str)[a]);
	curr_list = select_conv(spec, args);
	free(spec);
	if (a > 1)
	{
		curr_list->str = ft_strnjoin(ft_strcut(*str, a - 1), curr_list->str,
				curr_list->size);
		curr_list->size += a - 1;
	}
	*str = &(*str)[i + 1];
	return (curr_list);
}

static t_handlers	tabinit(char conv, t_list *(*fct)(t_flags*, va_list))
{
	t_handlers	ptr;

	ptr.conv = conv;
	ptr.fct_handle = fct;
	return (ptr);
}

void				ft_printf_utils_norme(char **rst, int *i, char *tmp)
{
	(*rst)[i[0]] = '\0';
	free(i);
	free(tmp);
}

t_list				*select_conv(t_flags *spec, va_list args)
{
	t_handlers	tab_handlers[15];
	int			i;

	tab_handlers[0] = tabinit('%', &ftprintf_handle_percent);
	tab_handlers[1] = tabinit('c', &ftprintf_handle_char);
	tab_handlers[2] = tabinit('s', &ftprintf_handle_str);
	tab_handlers[3] = tabinit('d', &ftprintf_handle_signed_int);
	tab_handlers[4] = tabinit('D', &ftprintf_handle_signed_int);
	tab_handlers[5] = tabinit('i', &ftprintf_handle_signed_int);
	tab_handlers[6] = tabinit('u', &ftprintf_handle_unsigned_int);
	tab_handlers[7] = tabinit('U', &ftprintf_handle_unsigned_int);
	tab_handlers[8] = tabinit('o', &ftprintf_handle_oct);
	tab_handlers[9] = tabinit('O', &ftprintf_handle_oct);
	tab_handlers[10] = tabinit('x', &ftprintf_handle_hex);
	tab_handlers[11] = tabinit('X', &ftprintf_handle_hex);
	tab_handlers[12] = tabinit('p', &ftprintf_handle_p);
	tab_handlers[13] = tabinit('f', &ftprintf_handle_float);
	tab_handlers[14] = tabinit('F', &ftprintf_handle_float);
	i = -1;
	while (++i < 15)
	{
		if (tab_handlers[i].conv == spec->conv)
			return (tab_handlers[i].fct_handle(spec, args));
	}
	return (NULL);
}
