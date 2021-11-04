/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 20:52:41 by leng-chu          #+#    #+#             */
/*   Updated: 2021/11/04 22:08:00 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(int *a, int top)
{
	int	tmp;

	tmp = a[top];
	a[top] = a[top - 1];
	a[top - 1] = tmp;
}

void	swap_b(int *b, int top)
{
	int	tmp;

	tmp = b[top];
	b[top] = b[top - 1];
	b[top - 1] = tmp;
}

void	push_a(int *a, int *b, int *topa, int *topb)
{
	int	tmp;

	if (*topb == -1)
		return ;
	tmp = b[*topb];
	*topa = *topa + 1;
	b[*topb] = a[*topa];
	a[*topa] = tmp;
	a[*topa + 1] = '\0';
	*topb -= 1;
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
}
