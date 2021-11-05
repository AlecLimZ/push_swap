/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swapush2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <-chu@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 10:20:46 by leng-chu          #+#    #+#             */
/*   Updated: 2021/11/05 15:27:08 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_cswap(int i)
{
	if (i == 0 && g_topa >= 1)
	{
		ft_swap('a');
		ft_putstr("sa\n");
	}
	else if (i == 1 && g_topb >= 1)
	{
		ft_swap('b');
		ft_putstr("sb\n");
	}
	else if (i == 2 && g_topa >= 1 && g_topb >= 1)
	{
		ft_swap('a');
		ft_swap('b');
		ft_putstr("ss\n");
	}
}

void	ft_reverse(char c)
{
	int	tmp;
	int	n;

	n = 0;
	if (c == 'a')
	{
		tmp = g_stacka[n--];
		while (++n < g_topa)
			g_stacka[n] = g_stacka[n + 1];
		g_stacka[n] = tmp;
	}
	else if (c == 'b')
	{
		tmp = g_stackb[n--];
		while (++n < g_topb)
			g_stackb[n] = g_stackb[n + 1];
		g_stackb[n] = tmp;
	}
}

void	ft_creverse(int i)
{
	if (i == 0 && g_topa >= 2)
	{
		ft_reverse('a');
		ft_putstr("rra\n");
	}
	else if (i == 1 && g_topb >= 2)
	{
		ft_reverse('b');
		ft_putstr("rrb\n");
	}
	else if (i == 2 && g_topa >= 2 && g_topb >= 2)
	{
		ft_reverse('a');
		ft_reverse('b');
		ft_putstr("rrr\n");
	}
}

int		ft_isallgood(void)
{
	int top;

	if (g_topa != (g_size - 1))
		return (0);
	top = g_topa;
	while (top > 0)
	{
		if (g_stacka[top] > g_stacka[top - 1])
			return (0);
		top--;
	}
	return (1);
}
