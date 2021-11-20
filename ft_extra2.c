/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <-chu@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 17:34:33 by leng-chu          #+#    #+#             */
/*   Updated: 2021/11/20 16:18:41 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	winnerone(int pos1, int *holdp, int step1, t_stack *stack)
{
	int	i;

	i = 0;
	if (pos1 > stack->topa / 2)
		while (i <= stack->max)
			holdp[i++] += step1;
	else
		while (i <= stack->max)
			holdp[i++] -= step1;
}

void	winnertwo(int pos2, int *holdp, int step2, t_stack *stack)
{
	int	i;

	i = 0;
	if (pos2 > stack->topa / 2)
		while (i <= stack->max)
			holdp[i++] += step2;
	else
		while (i <= stack->max)
			holdp[i++] -= step2;
}
