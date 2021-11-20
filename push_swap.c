/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <-chu@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:33:30 by leng-chu          #+#    #+#             */
/*   Updated: 2021/11/20 16:20:52 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> 

void	display(t_stack *stack)
{
	int	tmp_a;
	int	tmp_b;

	tmp_a = stack->topa;
	tmp_b = stack->topb;
	printf("===Stack A===\n");
	while (tmp_a >= 0)
		printf("%d\n", stack->a[tmp_a--]);
	printf("===Stack B===\n");
	while (tmp_b >= 0)
		printf("%d\n", stack->b[tmp_b--]);
	printf("\n");
}

static void	ft_init(char **argv, int argc, t_stack *stack)
{
	int	j;
	int	tmp;

	j = 1;
	stack->topa = -1;
	stack->topb = -1;
	stack->size = argc - 1;
	stack->flag = 1;
	stack->max = 0;
	tmp = stack->size;
	while (--tmp >= 0)
	{
		stack->a[tmp] = ft_atoi(argv[j++]);
		stack->topa++;
	}
}

static void	ft_swapush(t_stack *stack)
{
	while (1)
	{
		rotate_algo(stack);
		swap_algo(stack);
		if (ft_isallgood(stack))
			break ;
		press_algo(stack);
		push_algo(stack);
		if (ft_isbothgood(stack))
		{
			ft_pushalla(stack);
			break ;
		}
	}
}

//static void	ft_insert(t_stack *stack)
//{
//	int	pos1;
//	int	pos2;
//
//	while (1)
//	{
//		if (ft_isallgood(stack))
//			break ;
//		pos1 = 0;
//		pos2 = 0;
//		twosmall(&pos1, &pos2, stack);
//		insert_algo(pos1, pos2, stack);
//		swap_algo(stack);
//		if (ft_isbothgood(stack))
//			break ;
//		if (stack->topa == -1)
//			break ;
//	}
//	ft_pushalla(stack);
//}

int	main(int argc, char **argv)
{
	int		chunk;
	t_stack	*stack;

	ft_malloc(&stack, argc);
	if (argc < 1 || !ft_checknum(argv, argc) || !stack
		|| !stack->a || !stack->b)
	{
		ft_putstr("Error\n");
		return (1);
	}
	ft_init(argv, argc, stack);
	if (argc <= 10)
		ft_swapush(stack);
	else if (argc > 10 && argc <= 101)
	{
		chunk = (stack->topa * 0.2);
		ft_quick(chunk, stack);
	}
	else
	{
		chunk = stack->topa / 10;
		ft_quick(chunk, stack);
	}
	ft_free(stack);
	return (0);
}
