/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <-chu@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:05:56 by leng-chu          #+#    #+#             */
/*   Updated: 2021/11/11 14:31:10 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	quick_algo(int pos1, int pos2, int *holdp, int max)
{
	int		step1;
	int		step2;
	int		i;
	char	winner;

	i = 0;
//	printf("===QUICK!!===\n");
	step1 = stepcount(pos1);
	step2 = stepcount(pos2);
//	printf("step1: %d\n", step1);
//	printf("step2: %d\n", step2);
	winner = '\0';
	if (step1 <= step2)
	{
		pushpos(pos1);
		if (pos1 > g_topa / 2)
			while (i <= max)
				holdp[i++] += step1;
		else
			while (i <= max)
				holdp[i++] -= step1;
		winner = '1';
	}
	else if (step1 > step2)
	{
		pushpos(pos2);
		if (pos2 > g_topa / 2)
			while (i <= max)
				holdp[i++] += step2;
		else
			while (i <= max)
				holdp[i++] -= step2;
		winner = '2';
	}
//	printf("step1: %d\n", step1);
//	printf("step2: %d\n", step2);
//	i = -1;
//	while (++i <= 10)
//		printf("new holdp[%d]: %d\n", i, holdp[i]);
//	printf("Winner: %c\n", winner);
//	printf("====END of Quick====\n");
	return (winner);
}

void	magicpush(int *holdp)
{
//	int	step1;
//	int	step2;
	int		top;
	int		i;
	int 	b;
	char	pivotp;
	int		max;

	i = 0;
	b = 0;
	top = (g_topa / 2) - 1;
	max = top;
//	printf("top: %d\n", top);
//	printf("top/2: %d\n", top / 2);
	while (i <= top)
	{
		//if (i == mid)
		//	pushpos(holdp[i++]);
		//else
//		printf("holdp[%d]: %d\n", i, holdp[i]);
//		printf("hold[top]: %d\n", holdp[top]);
		pivotp = quick_algo(holdp[i], holdp[top], holdp, max);
		if (pivotp == '1')
			i++;
		else
			top--;
//		printf("i: %d\n", i);
//		printf("top: %d\n", top);
	}
	ft_cswap(1);
}

void	ft_inithold(int *holdp)
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
	while (j < (g_topa / 2) - 1)
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

void	ft_quick(void)
{
	int	*holdp;
	int	i;

	i = 0;
	holdp = malloc(sizeof(int) * g_size);
	if (holdp)
	{
		while (g_topa > 1)
		{
			if (ft_isallgood())
				break ;
			ft_inithold(holdp);
			holdp = ft_sorthold(holdp);
//			while (i < g_topa / 2)
//				printf("ori holdp: %d\n", holdp[i++]);
			magicpush(holdp);
			if (ft_isbothgood())
				break ;
		}
		swap_algo();
	//	printf("===START insertquick===\n");
		ft_insertforquick();
	}
//	ft_quicktoa();
}
