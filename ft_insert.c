/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <-chu@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 18:42:20 by leng-chu          #+#    #+#             */
/*   Updated: 2021/11/09 15:13:21 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	secondsmall(int s1, int s2, int **pos2)
{
	int	j;

	j = -1;
	while (++j <= g_topa)
	{
		if (s2 > g_stacka[j] && g_stacka[j] != s1)
		{
			s2 = g_stacka[j];
			**pos2 = j;
		}
	}
}

void	twosmall(int *pos1, int *pos2)
{
	int	i;
	int	s1;
	int	s2;

	i = -1;
	s1 = g_stacka[0];
	s2 = g_stacka[0];
	while (++i <= g_topa)
	{
		if (s1 > g_stacka[i])
		{
			s2 = s1;
			*pos2 = *pos1;
			s1 = g_stacka[i];
			*pos1 = i;
		}
		if (s2 == s1)
		{
			s2 = g_stacka[1];
			*pos2 = 1;
		}
		secondsmall(s1, s2, &pos2);
	}
}

void	pushpos(int pos)
{
	if (g_topa == 1)
		swap_algo();
	if (pos < (g_topa / 2 + 1))
	{
		while (pos-- >= 0)
			ft_creverse(0);
	}
	else if (pos > (g_topa / 2))
	{
		while (pos < g_topa)
		{
			ft_crotate(0);
			pos++;
		}
	}
	else if (pos < g_topa)
		ft_creverse(0);
	push_b();
}

int	stepcount(int pos)
{
	int	i;

	i = 0;
	if (pos < (g_topa / 2 + 1))
		i = pos + 1;
	else if (pos >= (g_topa / 2))
		i = g_topa - pos;
	return (i);
}

void	insert_algo(int pos1, int pos2)
{
	int	step1;
	int	step2;

	step1 = stepcount(pos1);
	step2 = stepcount(pos2);
	if (step1 <= step2)
	{
		pushpos(pos1);
		if (pos1 > g_topa / 2)
			pos2 += step1;
		else
			pos2 -= step1;
		pushpos(pos2);
	}
	else if (step1 > step2)
	{
		pushpos(pos2);
		if (pos2 > g_topa / 2)
			pos1 += step2;
		else
			pos1 -= step2;
		pushpos(pos1);
	}
	swap_algo();
}
