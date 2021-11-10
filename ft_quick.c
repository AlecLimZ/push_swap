/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quick.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <-chu@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:05:56 by leng-chu          #+#    #+#             */
/*   Updated: 2021/11/10 16:44:36 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	quick_algo(int pos1, int pos2, int *holdp)
{
	int		step1;
	int		step2;
	int		i;
	char	winner;

	i = 0;
	printf("QUICK!!\n");
	step1 = stepcount(pos1);
	step2 = stepcount(pos2);
	winner = '\0';
	if (step1 <= step2)
	{
		pushpos(pos1);
		if (pos1 > g_topa / 2)
			while (i <= g_topa / 2 + 1)
				holdp[i++] += step1;
		else
			while (i <= g_topa / 2 + 1)
				holdp[i++] -= step1;
		winner = '1';
	}
	else if (step1 > step2)
	{
		pushpos(pos2);
		if (pos2 > g_topa / 2)
			while (i <= g_topa / 2 + 1)
				holdp[i++] += step2;
		else
			while (i <= g_topa / 2 + 1)
				holdp[i++] -= step2;
		winner = '2';
	}
	printf("step1: %d\n", step1);
	printf("step2: %d\n", step2);
	i = 0;
	while (i <= g_topa / 2 + 1)
		printf("new holdp[i]: %d\n", holdp[i++]);
	return (winner);
}

void	magicpush(int *holdp)
{
//	int	step1;
//	int	step2;
	int		top;
	int		mid;
	int		i;
	int 	b;
	char	pivotp;

	i = 0;
	b = 0;
	top = g_topa / 2;
	mid = top / 2;
	printf("top: %d\n", top);
//	printf("top/2: %d\n", top / 2);
	while (i <= top + 1)
	{
		printf ("i: %d\n", i);
		if (i == mid)
			pushpos(holdp[i++]);
		else
			pivotp = quick_algo(holdp[i], holdp[top], holdp);
		if (pivotp == '1')
			i++;
		else
			top--;
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
	while (j < g_topa / 2)
	{
		p = nextsmall(s, &pos);
		s = p;
		holdp[i++] = pos;
		j++;
	}
	holdp[i] = '\0';
}

void	ft_quick(void)
{
	int	*holdp;
//	int	i;

//	i = 0;
	holdp = malloc(sizeof(int) * g_size);
	if (holdp)
	{
		//while (g_topa > 1)
		//{
		//	if (ft_isallgood())
		//		break ;
			ft_inithold(holdp);
			holdp = ft_sorthold(holdp);
//			while (i < g_topa / 2 + 1)
//				printf("ori holdp: %d\n", holdp[i++]);
			magicpush(holdp);
		//	if (ft_isbothgood())
		//		break ;
		//}
	}
//	ft_pushalla();
}
