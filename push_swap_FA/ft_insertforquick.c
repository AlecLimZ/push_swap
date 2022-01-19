/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insertforquick.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <-chu@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 11:14:47 by leng-chu          #+#    #+#             */
/*   Updated: 2021/11/20 16:13:17 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	secondbig(int s1, int s2, int **pos2, t_stack *stack)
{
	int	j;

	j = -1;
	while (++j <= stack->topb)
	{
		if (s2 < stack->b[j] && stack->b[j] != s1)
		{
			s2 = stack->b[j];
			**pos2 = j;
		}
	}
}

static void	twobig(int *pos1, int *pos2, t_stack *stack)
{
	int	i;
	int	s1;
	int	s2;

	i = -1;
	s1 = stack->b[0];
	s2 = stack->b[0];
	while (++i <= stack->topb)
	{
		if (s1 < stack->b[i])
		{
			s2 = s1;
			*pos2 = *pos1;
			s1 = stack->b[i];
			*pos1 = i;
		}
		if (s2 == s1)
		{
			s2 = stack->b[1];
			*pos2 = 1;
		}
		secondbig(s1, s2, &pos2, stack);
	}
}

static void	pushposbig(int pos, t_stack *stack)
{
	if (stack->topb == 1)
		swap_algo(stack);
	if (pos < (stack->topb / 2 + 1))
	{
		while (pos-- >= 0)
			ft_creverse(1, stack);
	}
	else if (pos > (stack->topb / 2))
	{
		while (pos < stack->topb)
		{
			ft_crotate(1, stack);
			pos++;
		}
	}
	else if (pos < stack->topb)
		ft_creverse(1, stack);
	push_a(stack);
}

static void	big_algo(int pos1, int pos2, t_stack *stack)
{
	int	step1;
	int	step2;

	step1 = stepcount_b(pos1, stack);
	step2 = stepcount_b(pos2, stack);
	if (step1 <= step2)
	{
		pushposbig(pos1, stack);
		if (pos1 > stack->topb / 2)
			pos2 += step1;
		else
			pos2 -= step1;
		pushposbig(pos2, stack);
	}
	else if (step1 > step2)
	{
		pushposbig(pos2, stack);
		if (pos2 > stack->topb / 2)
			pos1 += step2;
		else
			pos1 -= step2;
		pushposbig(pos1, stack);
	}
}

void	ft_insertforquick(t_stack *stack)
{
	int	pos1;
	int	pos2;
	int	c;

	c = 1;
	swap_algo(stack);
	while (c)
	{
		if (ft_isallgood(stack))
			break ;
		pos1 = 0;
		pos2 = 0;
		twobig(&pos1, &pos2, stack);
		big_algo(pos1, pos2, stack);
		swap_algo(stack);
		if (ft_isbothgood(stack))
			break ;
		if (stack->topb == -1)
			break ;
	}
	ft_quicktoa(stack);
}
