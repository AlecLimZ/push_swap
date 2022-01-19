/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <-chu@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 18:42:20 by leng-chu          #+#    #+#             */
/*   Updated: 2021/11/20 15:55:10 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	secondsmall(int s1, int s2, int **pos2, t_stack *stack)
{
	int	j;

	j = -1;
	while (++j <= stack->topa)
	{
		if (s2 > stack->a[j] && stack->a[j] != s1)
		{
			s2 = stack->a[j];
			**pos2 = j;
		}
	}
}

void	twosmall(int *pos1, int *pos2, t_stack *stack)
{
	int	i;
	int	s1;
	int	s2;

	i = -1;
	s1 = stack->a[0];
	s2 = stack->a[0];
	while (++i <= stack->topa)
	{
		if (s1 > stack->a[i])
		{
			s2 = s1;
			*pos2 = *pos1;
			s1 = stack->a[i];
			*pos1 = i;
		}
		if (s2 == s1)
		{
			s2 = stack->a[1];
			*pos2 = 1;
		}
		secondsmall(s1, s2, &pos2, stack);
	}
}

void	pushpos(int pos, t_stack *stack)
{
	if (stack->topa == 1)
		swap_algo(stack);
	if (pos < (stack->topa / 2 + 1))
	{
		while (pos-- >= 0)
			ft_creverse(0, stack);
	}
	else if (pos > (stack->topa / 2))
	{
		while (pos < stack->topa)
		{
			ft_crotate(0, stack);
			pos++;
		}
	}
	else if (pos < stack->topa)
		ft_creverse(0, stack);
	push_b(stack);
}

int	stepcount(int pos, t_stack *stack)
{
	int	i;

	i = 0;
	if (pos < (stack->topa / 2 + 1))
		i = pos + 1;
	else if (pos >= (stack->topa / 2))
		i = stack->topa - pos;
	return (i);
}

void	insert_algo(int pos1, int pos2, t_stack *stack)
{
	int	step1;
	int	step2;

	step1 = stepcount(pos1, stack);
	step2 = stepcount(pos2, stack);
	if (step1 <= step2)
	{
		pushpos(pos1, stack);
		if (pos1 > stack->topa / 2)
			pos2 += step1;
		else
			pos2 -= step1;
		pushpos(pos2, stack);
	}
	else if (step1 > step2)
	{
		pushpos(pos2, stack);
		if (pos2 > stack->topa / 2)
			pos1 += step2;
		else
			pos1 -= step2;
		pushpos(pos1, stack);
	}
}
