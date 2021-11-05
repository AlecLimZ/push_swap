/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <-chu@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:28:49 by leng-chu          #+#    #+#             */
/*   Updated: 2021/11/05 15:08:56 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

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
void	display(void);

#endif
