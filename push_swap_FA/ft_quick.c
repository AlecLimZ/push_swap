/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <-chu@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:05:56 by leng-chu          #+#    #+#             */
/*   Updated: 2021/11/20 16:22:22 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	quick_algo(int pos1, int pos2, int *holdp, t_stack *stack)
{
	int		step1;
	int		step2;
	char	winner;

	step1 = stepcount(pos1, stack);
	step2 = stepcount(pos2, stack);
	winner = '\0';
	if (step1 <= step2)
	{
		pushpos(pos1, stack);
		winnerone(pos1, holdp, step1, stack);
		winner = '1';
	}
	else if (step1 > step2)
	{
		pushpos(pos2, stack);
		winnertwo(pos2, holdp, step2, stack);
		winner = '2';
	}
	return (winner);
}

static void	magicpush(int *holdp, int chunk, t_stack *stack)
{
	int		top;
	int		i;
	char	pivotp;

	i = 0;
	top = chunk;
	stack->max = top;
	while (i <= top)
	{
		pivotp = quick_algo(holdp[i], holdp[top], holdp, stack);
		if (pivotp == '1')
			i++;
		else
			top--;
	}
	ft_cswap(1, stack);
}

static void	ft_inithold(int *holdp, int chunk, t_stack *stack)
{
	int	i;
	int	j;
	int	p;
	int	s;
	int	pos;

	i = 0;
	j = 0;
	smallest(&s, &pos, stack);
	holdp[i++] = pos;
	while (j < chunk)
	{
		p = nextsmall(s, &pos, stack);
		s = p;
		holdp[i++] = pos;
		j++;
	}
	holdp[i] = '\0';
}

void	ft_quicktoa(t_stack *stack)
{
	int	b;

	b = stack->topb;
	while (b >= 0)
	{
		push_a(stack);
		b--;
	}
}

void	ft_quick(int chunk, t_stack *stack)
{
	int	*holdp;

	holdp = malloc(sizeof(int) * stack->size);
	if (holdp)
	{
		while (stack->topa > 1)
		{
			if (ft_isallgood(stack))
				break ;
			ft_inithold(holdp, chunk, stack);
			holdp = ft_sorthold(holdp, stack);
			magicpush(holdp, chunk, stack);
			if (ft_isbothgood(stack))
				break ;
		}
		ft_insertforquick(stack);
	}
	free(holdp);
}
