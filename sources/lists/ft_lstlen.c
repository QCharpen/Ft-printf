/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstlen.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qcharpen <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/08/17 01:29:37 by qcharpen     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/27 11:23:20 by qcharpen    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/lists.h"

size_t		ft_lstlen(t_list *list)
{
	size_t	len;

	len = 0;
	while (list)
	{
		if (list->size > 0)
			len += list->size;
		list = list->next;
	}
	return (len);
}
