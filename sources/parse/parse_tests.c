/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parse_tests.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qcharpen <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/03 17:49:47 by qcharpen     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/14 22:56:08 by qcharpen    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/parse.h"

int		is_conv(const char c)
{
	return (ft_strchr("%sdDioOuUxXcpfF", c) != NULL);
}

int		is_size(const char c)
{
	return (ft_strchr("hljz", c) != NULL);
}

int		is_flag(const char c)
{
	return (ft_strchr("0#-+ L", c) != NULL);
}

int		is_valid(const char c)
{
	return (is_conv(c) || is_size(c) || is_flag(c) || ft_isdigit(c)
			|| c == '.');
}
