/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qcharpen <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 16:56:48 by qcharpen     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/26 08:36:50 by qcharpen    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/libft.h"

static uintmax_t	ft_pow(uintmax_t nb, int pow)
{
	if (nb == 0)
		return (0);
	if (pow == 0)
		return (1);
	else if (pow > 0)
		return (nb * ft_pow(nb, pow - 1));
	else
		return (1 / ft_pow(nb, -pow));
}

static int			size_i(uintmax_t n, int base)
{
	int		i;

	i = 1;
	while (n >= base)
	{
		n = n / base;
		i++;
	}
	return (i);
}

static char			nbrbase(uintmax_t n, int i, int base, int maj)
{
	int		nbr;

	nbr = (uintmax_t)ABS((n / ft_pow(base, i)));
	if (nbr < 10)
		return (nbr + '0');
	else
	{
		if (maj)
			return (nbr + 'A' - 10);
		else
			return (nbr + 'a' - 10);
	}
}

char				*ft_itoa_base_unsigned(uintmax_t n, int base, int maj)
{
	char	*str;
	int		i;
	int		a;

	i = size_i(n, base);
	if (!(str = (char*)malloc(sizeof(*str) * (i + 1))))
		return (NULL);
	a = 0;
	while (i > 0)
	{
		i--;
		str[a] = nbrbase(n, i, base, maj);
		n = n % ft_pow(base, i);
		a++;
	}
	str[a] = 0;
	return (str);
}
