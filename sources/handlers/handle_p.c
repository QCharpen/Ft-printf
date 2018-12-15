/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   handle_p.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qcharpen <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/25 06:55:25 by qcharpen     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/12 07:31:31 by gmadec      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

t_list	*arg_zero(t_flags *spec)
{
	char	*rst;
	int		len;
	int		i;

	if (spec->prec == -1)
		spec->prec = 1;
	len = MAX(spec->prec + 2, spec->width);
	rst = ft_memalloc(sizeof(*rst) * len);
	i = 0;
	if (!spec->flags[minus])
		while (i < len - 3)
			rst[i++] = ' ';
	rst[i++] = '0';
	rst[i++] = 'x';
	if (spec->prec != 0)
		rst[i++] = '0';
	while (i < len)
		rst[i++] = ' ';
	rst[i] = '\0';
	return (ft_lstnew(rst, ft_strlen(rst)));
}

t_list	*ftprintf_handle_p(t_flags *spec, va_list args)
{
	char	*rst;
	char	*tmp;
	void	*arg;
	int		*i;
	int		len;

	arg = va_arg(args, void*);
	if (arg == 0)
		return (arg_zero(spec));
	tmp = ft_itoa_base_unsigned((long int)arg, 16, 0);
	if (spec->width == -1)
		spec->width = 0;
	len = MAX(spec->prec + 3, MAX(ft_strlen(tmp) + 3, spec->width + 1));
	rst = ft_memalloc(sizeof(*tmp) * len);
	i = ft_tabset(2);
	while (!spec->flags[minus] && spec->width > (i[0] + ft_strlen(tmp) + 2))
		rst[(i[0])++] = ' ';
	rst[(i[0])++] = '0';
	rst[(i[0])++] = 'x';
	while (tmp[i[1]])
		rst[(i[0])++] = tmp[i[1]++];
	while (i[0] < spec->width)
		rst[(i[0])++] = ' ';
	ft_printf_utils_norme(&rst, i, tmp);
	return (ft_lstnew(rst, ft_strlen(rst)));
}
