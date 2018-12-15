/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qcharpen <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 16:57:48 by qcharpen     #+#   ##    ##    #+#       */
/*   Updated: 2018/09/29 21:58:53 by qcharpen    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char*)malloc(sizeof(*str) * (ft_strlen(s1) + 1));
	if (str == NULL)
		return (NULL);
	{
		while (s1[i])
		{
			str[i] = s1[i];
			i++;
		}
	}
	while (i < ft_strlen(s1) + 1)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}
