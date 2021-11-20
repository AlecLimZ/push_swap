/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <-chu@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:28:49 by leng-chu          #+#    #+#             */
/*   Updated: 2021/11/20 21:47:32 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int	*a;
	int	*b;
	int	topa;
	int	topb;
	int	size;
	int	flag;
	int	max;
}	t_stack;

// inside push_swap.c
void	display(t_stack *stack);
void	ft_swapush(t_stack *stack);

// inside functions.c
int		ft_atoi(char *s);
int		ft_checknum(char *s[], int size);
void	ft_putstr(char *s);

// inside functions2.c
char	*ft_itoa(int n);
int		ft_isbothgood(t_stack *stack);
void	ft_pushalla(t_stack *stack);
void	ft_malloc(t_stack **stack, int argc);

// inside ft_swapush1.c
void	ft_swap(char c, t_stack *stack);
void	push_a(t_stack *stack);
void	push_b(t_stack *stack);
void	ft_rotate(char c, t_stack *stack);
void	ft_crotate(int i, t_stack *stack);

// inside ft_swapush2.c
int		ft_isallgood(t_stack *stack);
void	ft_reverse(char c, t_stack *stack);
void	ft_creverse(int i, t_stack *stack);
void	ft_cswap(int i, t_stack *stack);
int		ft_strcmp(const char *s1, const char *s2);

// inside ft_algo.c
void	rotate_algo(t_stack *stack);
void	swap_algo(t_stack *stack);
void	push_algo(t_stack *stack);
void	press_algo(t_stack *stack);
void	reverse_algo(t_stack *stack);

// inside ft_insert.c
void	twosmall(int *pos1, int *pos2, t_stack *stack);
void	insert_algo(int pos1, int pos2, t_stack *stack);
int		stepcount(int pos, t_stack *stack);
void	pushpos(int pos, t_stack *stack);

// inside ft_quick.c
void	ft_quick(int chunk, t_stack *stack);
void	ft_quicktoa(t_stack *stack);

// inside ft_insertforquick.c
void	ft_insertforquick(t_stack *stack);

// inside ft_extra.c
int		*ft_sorthold(int *hold, t_stack *stack);
void	smallest(int *s, int *pos, t_stack *stack);
int		nextsmall(int s, int *pos, t_stack *stack);
int		stepcount_b(int pos, t_stack *stack);
void	ft_free(t_stack *stack);

// inside ft_extra2.c
void	winnerone(int pos1, int *holdp, int step1, t_stack *stack);
void	winnertwo(int pos2, int *holdp, int step2, t_stack *stack);
void	fix_algo(t_stack *stack);
//int		ft_strintlen(int *s);

#endif
