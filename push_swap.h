/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <-chu@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:28:49 by leng-chu          #+#    #+#             */
/*   Updated: 2021/11/10 14:33:36 by leng-chu         ###   ########.fr       */
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

int		ft_atoi(char *s);
int		ft_checknum(char *s[], int size);
void	ft_putstr(char *s);
void	ft_swap(char c);
void	push_a(void);
void	push_b(void);
void	ft_rotate(char c);
void	ft_crotate(int i);
void	ft_reverse(char c);
void	ft_creverse(int i);
void	ft_cswap(int i);
int		ft_isallgood(void);
void	rotate_algo(void);
void	swap_algo(void);
void	push_algo(void);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_itoa(int n);
void	display(void);
int		ft_isbothgood(void);
void	ft_pushalla(void);
void	press_algo(void);
void	reverse_algo(void);
void	twosmall(int *pos1, int *pos2);
void	insert_algo(int pos1, int pos2);
void	ft_quick(void);
int		*ft_sorthold(int *hold);
int		stepcount(int pos);
int		ft_strintlen(int *s);
void	pushpos(int pos);
void	smallest(int *s, int *pos);
int		nextsmall(int s, int *pos);

#endif
