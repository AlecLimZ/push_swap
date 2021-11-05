/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <-chu@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 14:01:40 by leng-chu          #+#    #+#             */
/*   Updated: 2021/11/05 15:40:13 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_algo(void)
{
	if (g_topa >= 2)
	{
		if (g_stacka[0] < g_stacka[g_topa] && g_stackb[0] > g_stackb[g_topb])
			ft_crotate(2);
		else if (g_stacka[0] < g_stacka[g_topa])
			ft_crotate(0);
		else if (g_stackb[0] > g_stackb[g_topb])
			ft_crotate(1);
	}
}

void	swap_algo(void)
{
	if (g_stacka[g_topa] > g_stacka[g_topa - 1] && g_stackb[g_topb] < g_stackb[g_topb - 1])
		ft_cswap(2);
	if (g_stacka[g_topa] > g_stacka[g_topa - 1])
		ft_cswap(0);
	else if (g_stackb[g_topb] < g_stackb[g_topb - 1])
		ft_cswap(1);
}

void	push_algo(void)
{
	if (g_topa == 1)
		g_flag = 0;
	if (g_flag == 1)
		push_b();
	if  (g_flag == 0 && g_topb != -1)
		push_a();
}
