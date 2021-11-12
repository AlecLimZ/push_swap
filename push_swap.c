/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <-chu@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:33:30 by leng-chu          #+#    #+#             */
/*   Updated: 2021/11/12 13:12:32 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> 

void	display(void)
{
	int	tmp_a;
	int	tmp_b;

	tmp_a = g_topa;
	tmp_b = g_topb;
	printf("===Stack A===\n");
	while (tmp_a >= 0)
		printf("%d\n", g_stacka[tmp_a--]);
	printf("===Stack B===\n");
	while (tmp_b >= 0)
		printf("%d\n", g_stackb[tmp_b--]);
	printf("\n");
}

void	ft_init(char **argv, int argc)
{
	int	j;
	int	tmp;

	j = 1;
	g_topa = -1;
	g_topb = -1;
	g_size = argc - 1;
	g_flag = 1;
	tmp = g_size;
	while (--tmp >= 0)
	{
		g_stacka[tmp] = ft_atoi(argv[j++]);
		g_topa++;
	}
}

void	ft_swapush(void)
{
	while (1)
	{
		rotate_algo();
		swap_algo();
		if (ft_isallgood())
			break ;
		press_algo();
		push_algo();
		if (ft_isbothgood())
		{
			ft_pushalla();
			break ;
		}
	}
}

void	ft_insert(void)
{
	int	pos1;
	int	pos2;

	while (1)
	{
		if (ft_isallgood())
			break ;
		pos1 = 0;
		pos2 = 0;
		twosmall(&pos1, &pos2);
		insert_algo(pos1, pos2);
		swap_algo();
		if (ft_isbothgood())
			break ;
		if (g_topa == -1)
			break ;
	}
	ft_pushalla();
}

int	main(int argc, char **argv)
{
	int	chunk;

	g_stacka = malloc(sizeof(int) * argc);
	g_stackb = malloc(sizeof(int) * argc);
	if (argc < 1 || !ft_checknum(argv, argc) || !g_stacka || !g_stackb)
	{
		ft_putstr("Error\n");
		return (1);
	}
	ft_init(argv, argc);
	if (argc <= 10)
		ft_swapush();
	else
	{
		chunk = g_topa / 10;
		ft_quick(chunk, argc);
	}
	free(g_stacka);
	free(g_stackb);
	return (0);
}
