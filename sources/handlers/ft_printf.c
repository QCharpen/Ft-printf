/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qcharpen <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/26 16:09:48 by qcharpen     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/14 22:54:55 by qcharpen    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int			ret;
	va_list		args;
	void		*tmp;
	int			fd;

	fd = 1;
	tmp = &fd;
	if (!format || !*format)
		return (0);
	va_start(args, format);
	ret = ft_inner_printf(ft_lstprint, &tmp, args, format);
	va_end(args);
	return (ret);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	int			ret;
	va_list		args;
	void		*tmp;

	tmp = &fd;
	if (!format || !*format || fd < 0)
		return (0);
	va_start(args, format);
	ret = ft_inner_printf(ft_lstprint, &tmp, args, format);
	va_end(args);
	return (ret);
}

int	ft_sprintf(char **str, const char *format, ...)
{
	int			ret;
	va_list		args;
	void		*tmp;

	tmp = &str;
	if (!format || !*format)
		return (0);
	va_start(args, format);
	ret = ft_inner_printf(ft_lstsprint, &tmp, args, format);
	*str = tmp;
	va_end(args);
	return (ret);
}

int	ft_fprintf(char *str, const char *format, ...)
{
	int			ret;
	va_list		args;
	void		*tmp;

	tmp = str;
	if (!format || !*format)
		return (0);
	va_start(args, format);
	ret = ft_inner_printf(ft_lstfprint, &tmp, args, format);
	va_end(args);
	return (ret);
}

int	ft_inner_printf(int (*f)(void**, t_list*), void **fd, va_list args,
		const char *format)
{
	char		*str;
	int			i;
	t_list		*list;
	int			ret;

	str = (char*)format;
	i = 0;
	list = NULL;
	while (str[i])
	{
		if (str[i] == '%')
		{
			ft_lstaddend(&list, handle(&str, args, i + 1));
			i = -1;
		}
		i++;
	}
	if (i > 0)
		ft_lstaddend(&list, ft_lstnew(ft_strcut(str, i), i));
	ret = f(fd, list);
	free(list);
	return (ret);
}
