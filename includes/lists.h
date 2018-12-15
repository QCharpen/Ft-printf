/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lists.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qcharpen <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/07/05 18:23:59 by qcharpen     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/02 16:26:12 by qcharpen    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef LISTS_H
# define LISTS_H
# include "ft_printf.h"

typedef struct s_list	t_list;

struct			s_list
{
	char	*str;
	int		size;
	t_list	*next;
};

void			ft_lstaddend(t_list **alst, t_list *nxt);
void			ft_lstdel(t_list **alst);
t_list			*ft_lstnew(char *str, size_t len);
size_t			ft_lstlen(t_list *list);
int				ft_lstprint(void **fd, t_list *lst);
int				ft_lstsprint(void **fd, t_list *lst);
int				ft_lstfprint(void **fd, t_list *lst);

#endif
