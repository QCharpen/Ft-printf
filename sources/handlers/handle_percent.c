/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   handle_percent.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qcharpen <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/17 03:14:19 by qcharpen     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/17 21:54:23 by gmadec      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_list	*ftprintf_handle_percent(t_flags *spec, va_list args)
{
	char	*rst;
	int		len;
	int		i;

	len = MAX(1, spec->width);
	rst = ft_memalloc(sizeof(*rst) * (len + 1));
	i = 0;
	if (spec->flags[minus])
		rst[i++] = '%';
	while (i < len - 1 + spec->flags[minus])
		rst[i++] = (spec->flags[zero] ? '0' : ' ');
	if (!spec->flags[minus])
		rst[i++] = '%';
	rst[i] = '\0';
	return (ft_lstnew(rst, ft_strlen(rst)));
}
