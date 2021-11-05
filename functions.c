/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <-chu@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:31:24 by leng-chu          #+#    #+#             */
/*   Updated: 2021/11/05 18:12:05 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		write(1, &s[i], 1);
}

int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\r' || c == '\f' || c == ' ')
		return (1);
	return (0);
}

int	ft_isnum(char c)
{
	if ((c >= '0' && c <= '9') || c == '-')
		return (1);
	return (0);
}

int	ft_checknum(char *s[], int size)
{
	int	i;
	int	j;

	i = 0;
	while (++i < size)
	{
		j = -1;
		while (s[i][++j] != '\0')
			if (!ft_isnum(s[i][j]) || s[i][j + 1] == '-')
				return (0);
		if (ft_strcmp(s[i], ft_itoa(ft_atoi(s[i]))) != 0)
			return (0);
	}

	while (--i > 1)
	{
		j = i;
		while (--j >= 1)
			if (ft_atoi(s[i]) == ft_atoi(s[j]))
				return (0);
	}
	return (1);
}

int	ft_atoi(char *s)
{
	int			i;
	int			sign;
	long int	num;

	i = 0;
	sign = 1;
	num = 0;
	while (ft_isspace(s[i]))
		i++;
	while (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isnum(s[i]))
	{
		num = num * 10 + (s[i] - '0');
		i++;
	}
	return (num * sign);
}
