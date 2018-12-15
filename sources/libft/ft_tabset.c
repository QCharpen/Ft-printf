/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memset.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qcharpen <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 16:57:17 by qcharpen     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/26 08:48:55 by qcharpen    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_tabset(size_t len)
{
	int		*tab;

	tab = ft_memalloc(sizeof(*tab) * len);
	while (len > 0)
	{
		len--;
		tab[len] = 0;
	}
	return (tab);
}
