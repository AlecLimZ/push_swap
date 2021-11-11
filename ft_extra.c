/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <-chu@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:38:13 by leng-chu          #+#    #+#             */
/*   Updated: 2021/11/11 14:01:14 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	smallest(int *s, int *pos)
{
	int	i;

	i = -1;
	*s = INT_MAX;
	while (++i <= g_topa)
	{
		if (*s > g_stacka[i])
		{
			*s = g_stacka[i];
			*pos = i;
		}
	}
}

int	nextsmall(int s, int *pos)
{
	int	i;
	int	m;

	i = 0;
	m = INT_MAX;
	while (i <= g_topa)
	{
		if (m > g_stacka[i] && g_stacka[i] > s)
		{
			m = g_stacka[i];
			*pos = i;
		}
		i++;
	}
	return (m);
}

int	*ft_sorthold(int *hold)
{
	int	*sort;
	int	tmp;
	int	i;
	int	j;

	i = 0;
	sort = malloc(sizeof(int) * (g_topa / 2));
	if (sort)
	{
		while (i < g_topa / 2 + 1)
		{
			j = i;
			while (++j < g_topa / 2 + 1)
			{
				if (hold[i] < hold[j])
				{
					tmp = hold[i];
					hold[i] = hold[j];
					hold[j] = tmp;
				}
			}
			i++;
		}
	}
	return (hold);
}

int	stepcount_b(int pos)
{
	int	i;

	i = 0;
	if (pos < (g_topb / 2 + 1))
		i = pos + 1;
	else if (pos >= (g_topb / 2))
		i = g_topb - pos;
	return (i);
}
