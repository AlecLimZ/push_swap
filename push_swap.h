/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <-chu@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:28:49 by leng-chu          #+#    #+#             */
/*   Updated: 2021/11/04 22:07:01 by leng-chu         ###   ########.fr       */
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

int		ft_atoi(char *s);
int		ft_checknum(char *s[], int size);
void	ft_putstr(char *s);
void	swap_a(int *a, int top);
void	swap_b(int *b, int top);
void	push_a(int *a, int *b, int *topa, int *topb);
void	push_b(void);

#endif
