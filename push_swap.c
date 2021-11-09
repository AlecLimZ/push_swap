/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <-chu@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:33:30 by leng-chu          #+#    #+#             */
/*   Updated: 2021/11/09 18:15:58 by leng-chu         ###   ########.fr       */
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
	printf("===STACK A===\n");
	while (tmp_a >= 0)
		printf("%d\n", g_stacka[tmp_a--]);
	printf("===STACK B===\n");
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
//	while (!ft_isallgood())
//	{
//		rotate_algo();
//		swap_algo();
//		if (ft_isallgood())
//			break ;
//		push_algo();
//	}
	while (1)
	{
		rotate_algo();
		swap_algo();
//		reverse_algo();
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
//	display();
}

void	ft_insert(void)
{
	int	pos1;
	int	pos2;

	int c = 1;
	while (c)
	{
		if (ft_isallgood())
			break ;
	//	swap_algo();
		pos1 = 0;
		pos2 = 0;
		twosmall(&pos1, &pos2);
		insert_algo(pos1, pos2);
		if (ft_isbothgood())
			break ;
		if (g_topa == -1)
			break ;
	}
//	swap_algo();
	ft_pushalla();
}

int	main(int argc, char **argv)
{
	g_stacka = malloc(sizeof(int) * argc);
	g_stackb = malloc(sizeof(int) * argc);
	if (argc < 1 || !ft_checknum(argv, argc) || !g_stacka || !g_stackb)
	{
		ft_putstr("Error\n");
		return (1);
	}
	ft_init(argv, argc);
//	if (argc <= 6)
//		ft_swapush();
//	else
//		ft_insert();
	ft_quick();
//	display();
	free(g_stacka);
	free(g_stackb);
	return (0);
}
