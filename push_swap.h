/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <-chu@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:28:49 by leng-chu          #+#    #+#             */
/*   Updated: 2021/11/13 18:26:55 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <limits.h>

int	*g_stacka;
int	*g_stackb;
int	g_topa;
int	g_topb;
int	g_size;
int	g_flag;

// inside push_swap.c
void	display(void);

// inside functions.c
int		ft_atoi(char *s);
int		ft_checknum(char *s[], int size);
void	ft_putstr(char *s);

// inside functions2.c
char	*ft_itoa(int n);
int		ft_isbothgood(void);
void	ft_pushalla(void);

// inside ft_swapush1.c
void	ft_swap(char c);
void	push_a(void);
void	push_b(void);
void	ft_rotate(char c);
void	ft_crotate(int i);

// inside ft_swapush2.c
int		ft_isallgood(void);
void	ft_reverse(char c);
void	ft_creverse(int i);
void	ft_cswap(int i);
int		ft_strcmp(const char *s1, const char *s2);

// inside ft_algo.c
void	rotate_algo(void);
void	swap_algo(void);
void	push_algo(void);
void	press_algo(void);
void	reverse_algo(void);

// inside ft_insert.c
void	twosmall(int *pos1, int *pos2);
void	insert_algo(int pos1, int pos2);
int		stepcount(int pos);
void	pushpos(int pos);

// inside ft_quick.c
void	ft_quick(int chunk);
void	ft_quicktoa(void);

// inside ft_insertforquick.c
void	ft_insertforquick(void);

// inside ft_extra.c
int		*ft_sorthold(int *hold);
void	smallest(int *s, int *pos);
int		nextsmall(int s, int *pos);
int		stepcount_b(int pos);

// inside ft_extra2.c
void	winnerone(int pos1, int *holdp, int max, int step1);
void	winnertwo(int pos2, int *holdp, int max, int step2);
//int		ft_strintlen(int *s);

#endif
