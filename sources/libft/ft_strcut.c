/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcut.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qcharpen <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/06/27 17:50:27 by qcharpen     #+#   ##    ##    #+#       */
/*   Updated: 2018/07/15 08:55:59 by qcharpen    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strcut(const char *s, size_t i)
{
	size_t	j;
	char	*rst;

	if (i <= 0)
		return (NULL);
	if (i > ft_strlen(s))
		i = ft_strlen(s);
	rst = (char*)ft_memalloc(sizeof(*rst) * (i + 1));
	j = 0;
	while (j < i && s[j])
	{
		rst[j] = s[j];
		j++;
	}
	rst[j] = '\0';
	return (rst);
}
