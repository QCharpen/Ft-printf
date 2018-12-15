/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsub.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: dzonda <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/12 20:14:26 by dzonda       #+#   ##    ##    #+#       */
/*   Updated: 2018/11/22 07:22:19 by gmadec      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/libft.h"

char		*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	str = NULL;
	i = -1;
	if (!s)
		return (NULL);
	start--;
	if (!(str = ft_strnew(len)))
		return (NULL);
	while (s[++start] && ++i < (int)len)
		str[i] = s[start];
	return (str);
}
