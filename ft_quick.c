/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <-chu@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:05:56 by leng-chu          #+#    #+#             */
/*   Updated: 2021/11/09 18:49:23 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	smallest(void)
{
	int	i;
	int m;

	i = 0;
	m = INT_MAX;
	while (i <= g_topa)
	{
		if (m > g_stacka[i])
			m = g_stacka[i];
		i++;
	}
	return (m);
}

int	nextsmall(int s)
{
	int	i;
	int m;

	i = 0;
	m = INT_MAX;
	while (i <= g_topa)
	{
		if (m > g_stacka[i] && g_stacka[i] > s)
			m = g_stacka[i];
		i++;
	}
	return (m);
}
void	ft_quick(void)
{
	int	i;
	int	j;
	int	hold[100];
	int p = g_stacka[g_topa];
	int	s;

	i = 0;
	j = 0;
	s = smallest();
	hold[i++] = s;
	while (j < g_topa / 2)
	{
		p = nextsmall(s);
		printf("p: %d\n", p);
		s = p;
		hold[i++] = p;
		j++;
	}
	hold[i] = '\0';
	i = 0;
	while (i < g_topa / 2 + 1)
		printf("hold: %d\n", hold[i++]);
}
