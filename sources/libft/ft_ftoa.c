/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ftoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: qcharpen <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/11/22 13:03:07 by qcharpen     #+#   ##    ##    #+#       */
/*   Updated: 2018/12/15 01:33:31 by qcharpen    ###    #+. /#+    ###.fr     */
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

double					next_n(double n, int ent)
{
	int		i;

	i = ABS(n / ft_pow(10, ent - 1));
	if (n > 0)
		n -= i * (ft_pow(10, ent - 1));
	else
		n += i * (ft_pow(10, ent - 1));
	return (n);
}

void					end_of_ftoa(int dec, long double n, int i, char **str)
{
	while (dec > 0)
	{
		n *= 10;
		(*str)[i++] = ((int)n) + '0';
		n -= ((int)n);
		dec--;
		if (dec == 0 && ABS(n * 10) >= 5)
			str[i - 1]++;
	}
	(*str)[i++] = '\0';
}

char					*ft_ftoa(long double n, int dec)
{
	int		ent;
	char	*str;
	int		i;

	ent = 1;
	i = 0;
	while (n > ft_pow(10, ent) || n < -ft_pow(10, ent))
		ent++;
	str = ft_memalloc(sizeof(*str) * (dec + ent + 2 + (n < 0 ? 1 : 0)));
	if (n < 0)
	{
		n *= -1;
		str[i++] = '-';
	}
	while (ent > 0)
	{
		str[i++] = ABS(n / ft_pow(10, ent - 1)) + '0';
		n = next_n(n, ent);
		ent--;
	}
	if (dec > 0)
		str[i++] = '.';
	end_of_ftoa(dec, n, i, &str);
	return (str);
}
