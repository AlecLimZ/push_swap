/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insertforquick.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <-chu@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 11:14:47 by leng-chu          #+#    #+#             */
/*   Updated: 2021/11/11 14:43:45 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	secondbig(int s1, int s2, int **pos2)
{
	int	j;

	j = -1;
	while (++j <= g_topb)
	{
		if (s2 < g_stackb[j] && g_stackb[j] != s1)
		{
			s2 = g_stackb[j];
			**pos2 = j;
		}
	}
}

void	twobig(int *pos1, int *pos2)
{
	int	i;
	int	s1;
	int	s2;

	i = -1;
	s1 = g_stackb[0];
	s2 = g_stackb[0];
	while (++i <= g_topb)
	{
		if (s1 < g_stackb[i])
		{
			s2 = s1;
			*pos2 = *pos1;
			s1 = g_stackb[i];
			*pos1 = i;
		}
		if (s2 == s1)
		{
			s2 = g_stackb[1];
			*pos2 = 1;
		}
		secondbig(s1, s2, &pos2);
	}
}

void	pushposbig(int pos)
{
	if (g_topb == 1)
		swap_algo();
	if (pos < (g_topb / 2 + 1))
	{
		while (pos-- >= 0)
			ft_creverse(1);
	}
	else if (pos > (g_topb / 2))
	{
		while (pos < g_topb)
		{
			ft_crotate(1);
			pos++;
		}
	}
	else if (pos < g_topb)
		ft_creverse(1);
	push_a();
}

void	big_algo(int pos1, int pos2)
{
	int	step1;
	int	step2;

	step1 = stepcount_b(pos1);
	step2 = stepcount_b(pos2);
	if (step1 <= step2)
	{
		pushposbig(pos1);
		if (pos1 > g_topb / 2)
			pos2 += step1;
		else
			pos2 -= step1;
		pushposbig(pos2);
	}
	else if (step1 > step2)
	{
		pushposbig(pos2);
		if (pos2 > g_topb / 2)
			pos1 += step2;
		else
			pos1 -= step2;
		pushposbig(pos1);
	}
}

void	ft_insertforquick(void)
{
	int	pos1;
	int	pos2;
	int	c;

	c = 1;
	swap_algo();
	while (c)
	{
		if (ft_isallgood())
			break ;
		pos1 = 0;
		pos2 = 0;
		twobig(&pos1, &pos2);
		big_algo(pos1, pos2);
		swap_algo();
		if (ft_isbothgood())
			break ;
		if (g_topb == -1)
			break ;
	}
	ft_quicktoa();
}
