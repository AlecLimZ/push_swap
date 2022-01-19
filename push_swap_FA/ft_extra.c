/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <-chu@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:38:13 by leng-chu          #+#    #+#             */
/*   Updated: 2021/11/21 09:13:13 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	smallest(int *s, int *pos, t_stack *stack)
{
	int	i;

	i = -1;
	*s = INT_MAX;
	while (++i <= stack->topa)
	{
		if (*s > stack->a[i])
		{
			*s = stack->a[i];
			*pos = i;
		}
	}
}

int	nextsmall(int s, int *pos, t_stack *stack)
{
	int	i;
	int	m;

	i = 0;
	m = INT_MAX;
	while (i <= stack->topa)
	{
		if (m > stack->a[i] && stack->a[i] > s)
		{
			m = stack->a[i];
			*pos = i;
		}
		i++;
	}
	return (m);
}

int	*ft_sorthold(int *hold, t_stack *stack)
{
	int	tmp;
	int	i;
	int	j;

	i = 0;
	while (i < stack->topa / 2 + 1)
	{
		j = i;
		while (++j < stack->topa / 2 + 1)
		{
			if (hold[i] < hold[j])
			{
				tmp = hold[i];
				hold[i] = hold[j];
				hold[j] = tmp;
			}
		}
		i++;
	}
	return (hold);
}

int	stepcount_b(int pos, t_stack *stack)
{
	int	i;

	i = 0;
	if (pos < (stack->topb / 2 + 1))
		i = pos + 1;
	else if (pos >= (stack->topb / 2))
		i = stack->topb - pos;
	return (i);
}

void	ft_free(t_stack *stack)
{
	free(stack->a);
	free(stack->b);
	free(stack);
}
