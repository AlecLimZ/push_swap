/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <-chu@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 17:23:52 by leng-chu          #+#    #+#             */
/*   Updated: 2021/11/21 08:30:59 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_numlen(int n)
{
	int				len;
	unsigned int	i;

	if (n == 0)
		return (1);
	len = 0;
	i = n;
	if (n < 0)
	{
		len++;
		i = -i;
	}
	while (i > 0)
	{
		len++;
		i /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*str;
	long	nb;
	int		i;

	len = ft_numlen(n);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	nb = n;
	if (n < 0)
	{
		str[0] = '-';
		nb = -nb;
		i = 1;
	}
	else
		i = 0;
	while (--len >= i)
	{
		str[len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (str);
}

int	ft_isbothgood(t_stack *stack)
{
	int	a;
	int	b;

	a = stack->topa;
	b = stack->topb;
	while (a > 0)
	{
		if (stack->a[a] > stack->a[a - 1])
			return (0);
		a--;
	}
	while (b > 0)
	{
		if (stack->b[b] < stack->b[b - 1])
			return (0);
		b--;
	}
	return (1);
}

void	ft_pushalla(t_stack *stack)
{
	int	b;

	b = stack->topb;
	while (b >= 0)
	{
		push_a(stack);
		b--;
	}
}

void	ft_malloc(t_stack **stack, int argc)
{
	*stack = malloc(sizeof(t_stack));
	(**stack).a = malloc(sizeof(int) * argc);
	(**stack).b = malloc(sizeof(int) * argc);
	if ((**stack).a == NULL || (**stack).b == NULL)
	{
		free((**stack).a);
		free((**stack).b);
		free(stack);
		exit(1);
	}
}
