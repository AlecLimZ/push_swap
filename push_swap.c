/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <-chu@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:33:30 by leng-chu          #+#    #+#             */
/*   Updated: 2021/11/05 15:42:23 by leng-chu         ###   ########.fr       */
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
	int	topa;
	int	topb;

	topa = g_topa;
	topb = g_topb;
	while (!ft_isallgood())
	{
		rotate_algo();
		swap_algo();
		if (ft_isallgood())
			break ;
		push_algo();
	}
}

int	main(int argc, char **argv)
{
	g_stacka = malloc(sizeof(int) * argc);
	g_stackb = malloc(sizeof(int) * argc);
	if (argc <= 1 || !ft_checknum(argv, argc) || !g_stacka || !g_stackb)
	{
		ft_putstr("Error!\n");
		return (1);
	}
	ft_init(argv, argc);
	ft_swapush();
	display();
	free(g_stacka);
	free(g_stackb);
	return (0);
}
