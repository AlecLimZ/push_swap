/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <-chu@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 14:01:40 by leng-chu          #+#    #+#             */
/*   Updated: 2021/11/20 19:10:00 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_algo(t_stack *stack)
{
	if (stack->topa >= 2)
	{
		while (stack->a[0] < stack->a[stack->topa]
			&& stack->b[0] > stack->b[stack->topb])
			ft_crotate(2, stack);
		while (stack->a[0] < stack->a[stack->topa])
			ft_crotate(0, stack);
		while (stack->b[0] > stack->b[stack->topb])
			ft_crotate(1, stack);
	}
}

void	swap_algo(t_stack *stack)
{
	if (stack->a[stack->topa] > stack->a[stack->topa - 1]
		&& stack->b[stack->topb] < stack->b[stack->topb - 1])
		ft_cswap(2, stack);
	if (stack->a[stack->topa] > stack->a[stack->topa - 1])
		ft_cswap(0, stack);
	else if (stack->b[stack->topb] < stack->b[stack->topb - 1])
		ft_cswap(1, stack);
}

void	push_algo(t_stack *stack)
{
	if (stack->topa == 2)
		stack->flag = 0;
	if (stack->flag == 1)
		push_b(stack);
	if (stack->flag == 0 && stack->topb != -1)
		push_a(stack);
}

void	reverse_algo(t_stack *stack)
{
	if (stack->topa >= 2)
	{
		while (stack->a[stack->topa] > stack->a[0] && stack->a[1] > stack->a[0]
			&& stack->b[stack->topb] < stack->b[0] && stack->b[1] < stack->b[0])
			ft_creverse(2, stack);
		while (stack->a[stack->topa] < stack->a[0]
			&& stack->a[1] > stack->a[0] && stack->b[stack->topb] > stack->b[0]
			&& stack->b[1] < stack->b[0])
			ft_creverse(2, stack);
		while (stack->a[stack->topa] > stack->a[0] && stack->a[1] > stack->a[0])
			ft_creverse(0, stack);
		while (stack->b[stack->topb] < stack->b[0] && stack->b[1] < stack->b[0])
			ft_creverse(1, stack);
		while (stack->a[stack->topa] < stack->a[0]
			&& stack->a[1] > stack->a[0])
			ft_creverse(0, stack);
		while (stack->b[stack->topb] > stack->b[0]
			&& stack->b[1] < stack->b[0])
			ft_creverse(1, stack);
	}
}

void	press_algo(t_stack *stack)
{
	if (stack->a[stack->topa] > stack->b[stack->topb])
		push_a(stack);
}
