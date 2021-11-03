/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leng-chu <-chu@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:33:30 by leng-chu          #+#    #+#             */
/*   Updated: 2021/11/03 12:06:34 by leng-chu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> 

//stdio.h - temp for printf test

void	display(int arr[])
{
	int	i;

	i = -1;
	while (arr[++i])
		printf("%d\n", arr[i]);
}

void	ft_putstr(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		write(1, &s[i], 1);
}

int	main(int argc, char **argv)
{
	int		stack_a[argc];
	int		i;
	int		j;

	i = 0;
	j = 1;
	if (argc < 1)
	{
		ft_putstr("Error!\n");
		return (1);
	}
	while (argv[j])
		stack_a[i++] = ft_atoi(argv[j++]);
	stack_a[i] = '\0';
	display(stack_a);
	return (0);
}
