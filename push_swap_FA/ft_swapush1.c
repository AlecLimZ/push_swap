/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swapush1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <leng-chu@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 20:52:41 by leng-chu          #+#    #+#             */
/*   Updated: 2021/11/20 12:54:14 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(char c, t_stack *stack)
{
	int	tmp;

	if (c == 'a')
	{
		tmp = stack->a[stack->topa];
		stack->a[stack->topa] = stack->a[stack->topa - 1];
		stack->a[stack->topa - 1] = tmp;
	}
	else if (c == 'b')
	{
		tmp = stack->b[stack->topb];
		stack->b[stack->topb] = stack->b[stack->topb - 1];
		stack->b[stack->topb - 1] = tmp;
	}
}

void	push_a(t_stack *stack)
{
	int	tmp;

	if (stack->topb == -1)
		return ;
	tmp = stack->b[stack->topb];
	stack->topa++;
	stack->b[stack->topb] = stack->a[stack->topa];
	stack->a[stack->topa] = tmp;
	stack->a[stack->topa + 1] = '\0';
	stack->topb--;
	ft_putstr("pa\n");
}

void	push_b(t_stack *stack)
{
	int	tmp;

	if (stack->topa == -1)
		return ;
	tmp = stack->a[stack->topa];
	stack->topb++;
	stack->a[stack->topa] = stack->b[stack->topb];
	stack->b[stack->topb] = tmp;
	stack->b[stack->topb + 1] = '\0';
	stack->topa--;
	ft_putstr("pb\n");
}

void	ft_rotate(char c, t_stack *stack)
{
	int	tmp;
	int	n;

	if (c == 'a')
	{
		n = stack->topa;
		tmp = stack->a[n++];
		while (--n > 0)
			stack->a[n] = stack->a[n - 1];
		stack->a[n] = tmp;
	}
	else if (c == 'b')
	{
		n = stack->topb;
		tmp = stack->b[n++];
		while (--n > 0)
			stack->b[n] = stack->b[n - 1];
		stack->b[n] = tmp;
	}
}

void	ft_crotate(int i, t_stack *stack)
{
	if (i == 0)
	{
		ft_rotate('a', stack);
		ft_putstr("ra\n");
	}
	else if (i == 1)
	{
		ft_rotate('b', stack);
		ft_putstr("rb\n");
	}
	else if (i == 2)
	{
		ft_rotate('a', stack);
		ft_rotate('b', stack);
		ft_putstr("rr\n");
	}
}
