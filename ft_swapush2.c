/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swapush2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <-chu@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 10:20:46 by leng-chu          #+#    #+#             */
/*   Updated: 2021/11/20 15:27:37 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_cswap(int i, t_stack *stack)
{
	if (i == 0 && stack->topa >= 1)
	{
		ft_swap('a', stack);
		ft_putstr("sa\n");
	}
	else if (i == 1 && stack->topb >= 1)
	{
		ft_swap('b', stack);
		ft_putstr("sb\n");
	}
	else if (i == 2 && stack->topa >= 1 && stack->topb >= 1)
	{
		ft_swap('a', stack);
		ft_swap('b', stack);
		ft_putstr("ss\n");
	}
}

void	ft_reverse(char c, t_stack *stack)
{
	int	tmp;
	int	n;

	n = 0;
	if (c == 'a')
	{
		tmp = stack->a[n--];
		while (++n < stack->topa)
			stack->a[n] = stack->a[n + 1];
		stack->a[n] = tmp;
	}
	else if (c == 'b')
	{
		tmp = stack->b[n--];
		while (++n < stack->topb)
			stack->b[n] = stack->b[n + 1];
		stack->b[n] = tmp;
	}
}

void	ft_creverse(int i, t_stack *stack)
{
	if (i == 0 && stack->topa >= 2)
	{
		ft_reverse('a', stack);
		ft_putstr("rra\n");
	}
	else if (i == 1 && stack->topb >= 2)
	{
		ft_reverse('b', stack);
		ft_putstr("rrb\n");
	}
	else if (i == 2 && stack->topa >= 2 && stack->topb >= 2)
	{
		ft_reverse('a', stack);
		ft_reverse('b', stack);
		ft_putstr("rrr\n");
	}
}

int	ft_isallgood(t_stack *stack)
{
	int	top;

	if (stack->topa != (stack->size - 1))
		return (0);
	top = stack->topa;
	while (top > 0)
	{
		if (stack->a[top] > stack->a[top - 1])
			return (0);
		top--;
	}
	return (1);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}
