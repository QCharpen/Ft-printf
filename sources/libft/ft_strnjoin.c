/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qcharpen <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 16:57:52 by qcharpen     #+#   ##    ##    #+#       */
/*   Updated: 2018/11/17 18:34:12 by qcharpen    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strnjoin(char *s1, char *s2, int n)
{
	char	*str;
	int		i;
	int		i2;

	if (!s1)
		return (NULL);
	if (!s2)
	{
		str = ft_strdup(s1);
		return (str);
	}
	if (!(str = ft_memalloc(ft_strlen(s1) + n + 1)))
		return (NULL);
	i = -1;
	i2 = 0;
	while (s1[++i])
		str[i] = s1[i];
	while (i2 < n)
		str[i++] = s2[i2++];
	str[i] = '\0';
	free(s1);
	free(s2);
	return (str);
}
