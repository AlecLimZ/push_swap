/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <-chu@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 17:23:52 by leng-chu          #+#    #+#             */
/*   Updated: 2021/11/06 23:19:27 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_numlen(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	int		len;
	char	*str;
	long	nb;

	len = ft_numlen(n);
	str = malloc(sizeof(char) * len);
	if (!str)
		return (NULL);
	i = len;
	nb = n;
	if (n < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	if (nb == 0)
		str[0] = '0';
	while (nb > 0 && str[i] != '-')
	{
		str[--i] = '0' + (nb % 10);
		nb /= 10;
	}
	str[len] = '\0';
	return (str);
}

int	ft_isbothgood(void)
{
	int	a;
	int	b;

	a = g_topa;
	b = g_topb;
	while (a > 0)
	{
		if (g_stacka[a] > g_stacka[a - 1])
			return (0);
		a--;
	}
	while (b > 0)
	{
		if (g_stackb[b] < g_stackb[b - 1])
			return (0);
		b--;
	}
	return (1);
}

void	ft_pushalla(void)
{
	int	b;

	b = g_topb;
	while (b >= 0)
	{
		push_a();
		b--;
	}
}
