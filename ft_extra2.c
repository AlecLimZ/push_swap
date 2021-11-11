/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <-chu@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 17:34:33 by leng-chu          #+#    #+#             */
/*   Updated: 2021/11/11 17:44:45 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	winnerone(int pos1, int *holdp, int max, int step1)
{
	int	i;

	i = 0;
	if (pos1 > g_topa / 2)
		while (i <= max)
			holdp[i++] += step1;
	else
		while (i <= max)
			holdp[i++] -= step1;
}

void	winnertwo(int pos2, int *holdp, int max, int step2)
{
	int	i;

	i = 0;
	if (pos2 > g_topa / 2)
		while (i <= max)
			holdp[i++] += step2;
	else
		while (i <= max)
			holdp[i++] -= step2;
}
