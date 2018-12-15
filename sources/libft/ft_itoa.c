/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qcharpen <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/24 16:56:48 by qcharpen     #+#   ##    ##    #+#       */
/*   Updated: 2018/10/25 20:07:59 by qcharpen    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../../includes/libft.h"

static long long int	ft_pow(long long int nb, int pow)
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

static int				size_i(long long int n)
{
	int		i;

	i = 1;
	if (n < 0)
		i++;
	while (n >= 10 || n <= -10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char					*ft_itoa(long long int n)
{
	char	*str;
	int		i;
	int		a;

	i = size_i(n);
	if (!(str = (char*)malloc(sizeof(*str) * (i + 1))))
		return (NULL);
	a = 0;
	if (n < 0)
	{
		str[a++] = '-';
		i--;
	}
	while (i > 0)
	{
		i--;
		str[a] = (int)ABS((n / ft_pow(10, i))) + '0';
		n = n % (long long int)ft_pow(10, i);
		a++;
	}
	str[a] = 0;
	return (str);
}
