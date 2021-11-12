/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <-chu@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:05:56 by leng-chu          #+#    #+#             */
/*   Updated: 2021/11/12 13:12:09 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	quick_algo(int pos1, int pos2, int *holdp, int max)
{
	int		step1;
	int		step2;
	char	winner;

	step1 = stepcount(pos1);
	step2 = stepcount(pos2);
	winner = '\0';
	if (step1 <= step2)
	{
		pushpos(pos1);
		winnerone(pos1, holdp, max, step1);
		winner = '1';
	}
	else if (step1 > step2)
	{
		pushpos(pos2);
		winnertwo(pos2, holdp, max, step2);
		winner = '2';
	}
	return (winner);
}

void	magicpush(int *holdp, int chunk)
{
	int		top;
	int		i;
	char	pivotp;
	int		max;

	i = 0;
	top = chunk;
	max = top;
	while (i <= top)
	{
		pivotp = quick_algo(holdp[i], holdp[top], holdp, max);
		if (pivotp == '1')
			i++;
		else
			top--;
	}
	ft_cswap(1);
}

void	ft_inithold(int *holdp, int chunk, int argc)
{
	int	i;
	int	j;
	int	p;
	int	s;
	int	pos;

	i = 0;
	j = 0;
	smallest(&s, &pos);
	holdp[i++] = pos;
	if (argc > 10 && argc <= 101)
		chunk = (g_topa * 0.3);
	while (j < chunk)
	{
		p = nextsmall(s, &pos);
		s = p;
		holdp[i++] = pos;
		j++;
	}
	holdp[i] = '\0';
}

void	ft_quicktoa(void)
{
	int	b;

	b = g_topb;
	while (b >= 0)
	{
		push_a();
		b--;
	}
}

void	ft_quick(int chunk, int argc)
{
	int	*holdp;

	holdp = malloc(sizeof(int) * g_size);
	if (holdp)
	{
		while (g_topa > 1)
		{
			if (ft_isallgood())
				break ;
			ft_inithold(holdp, chunk, argc);
			holdp = ft_sorthold(holdp);
			magicpush(holdp, chunk);
			if (ft_isbothgood())
				break ;
		}
		ft_insertforquick();
	}
	free(holdp);
}
