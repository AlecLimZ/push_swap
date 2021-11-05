/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swapush1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 20:52:41 by leng-chu          #+#    #+#             */
/*   Updated: 2021/11/05 15:33:09 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(char c)
{
	int	tmp;

	if (c == 'a')
	{
		tmp = g_stacka[g_topa];
		g_stacka[g_topa] = g_stacka[g_topa - 1];
		g_stacka[g_topa - 1] = tmp;
	}
	else if (c == 'b')
	{
		tmp = g_stackb[g_topb];
		g_stackb[g_topb] = g_stackb[g_topb - 1];
		g_stackb[g_topb - 1] = tmp;
	}
}

void	push_a(void)
{
	int	tmp;

	if (g_topb == -1)
		return ;
	tmp = g_stackb[g_topb];
	g_topa++;
	g_stackb[g_topb] = g_stacka[g_topa];
	g_stacka[g_topa] = tmp;
	g_stacka[g_topa + 1] = '\0';
	g_topb--;
	ft_putstr("pa\n");
}

void	push_b(void)
{
	int	tmp;

	if (g_topa == -1)
		return ;
	tmp = g_stacka[g_topa];
	g_topb++;
	g_stacka[g_topa] = g_stackb[g_topb];
	g_stackb[g_topb] = tmp;
	g_stackb[g_topb + 1] = '\0';
	g_topa--;
	ft_putstr("pb\n");
}

void	ft_rotate(char c)
{
	int	tmp;
	int	n;

	if (c == 'a')
	{
		n = g_topa;
		tmp = g_stacka[n++];
		while (--n > 0)
			g_stacka[n] = g_stacka[n - 1];
		g_stacka[n] = tmp;
	}
	else if (c == 'b')
	{
		n = g_topb;
		tmp = g_stackb[n++];
		while (--n > 0)
			g_stackb[n] = g_stackb[n - 1];
		g_stackb[n] = tmp;
	}
}

void	ft_crotate(int i)
{
	if (i == 0)
	{
		ft_rotate('a');
		ft_putstr("ra\n");
	}
	else if (i == 1)
	{
		ft_rotate('b');
		ft_putstr("rb\n");
	}
	else if (i == 2)
	{
		ft_rotate('a');
		ft_rotate('b');
		ft_putstr("rr\n");
	}
}
