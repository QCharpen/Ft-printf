/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstprint.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qcharpen <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/09/29 21:35:10 by qcharpen     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/14 22:52:51 by qcharpen    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/lists.h"

static void		lstjoin(t_list *lst2, t_list **lst)
{
	int			i;
	int			j;
	char		*s;

	s = ft_memalloc(sizeof((*lst)->str) * ((*lst)->size + lst2->size + 1));
	i = 0;
	j = 0;
	while (i < (*lst)->size)
	{
		s[i] = (*lst)->str[i];
		i++;
	}
	while (j < lst2->size)
		s[i++] = lst2->str[j++];
	s[i] = '\0';
	(*lst)->size = (*lst)->size + lst2->size;
	free((*lst)->str);
	(*lst)->str = s;
}

static t_list	*lstjoin_free(t_list *lst)
{
	t_list		*rst;
	t_list		*tmp;

	while (lst->next)
	{
		tmp = lst->next;
		lstjoin(tmp, &lst);
		lst->next = tmp->next ? tmp->next : NULL;
		free(tmp->str);
		free(tmp);
	}
	return (lst);
}

int				ft_lstfprint(void **str, t_list *lst)
{
	t_list		*tmp;
	int			fd;

	if (access((char*)*str, W_OK))
	{
		if ((fd = open((char*)*str,
			O_CREAT | O_APPEND | O_WRONLY, 0770)))
		{
			tmp = lstjoin_free(lst);
			write(fd, tmp->str, tmp->size);
		}
		else
			lst->size = 0;
	}
	else
		lst->size = 0;
	free(tmp->str);
	return (tmp->size);
}

int				ft_lstsprint(void **str, t_list *lst)
{
	t_list		*tmp;

	tmp = lst;
	tmp = lstjoin_free(lst);
	*str = tmp->str;
	return (tmp->size);
}

int				ft_lstprint(void **fd, t_list *lst)
{
	t_list		*tmp;

	tmp = lstjoin_free(lst);
	write(*((int*)fd[0]), tmp->str, tmp->size);
	free(tmp->str);
	return (tmp->size);
}
