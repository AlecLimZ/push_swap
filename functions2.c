/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <-chu@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 17:23:52 by leng-chu          #+#    #+#             */
/*   Updated: 2021/11/05 17:58:20 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_numlen(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n > 0)
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
	while (nb > 0 && str[i] != '-')
	{
		str[--i] = '0' + (nb % 10);
		nb /= 10;
	}
	str[len] = '\0';
	return (str);
}
