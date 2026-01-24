/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabuawad <yabuawad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 18:03:50 by yabuawad          #+#    #+#             */
/*   Updated: 2026/01/03 14:55:19 by yabuawad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checks(long num, char **splitted, int *arr, int x)
{
	if (num > 2147483647 || num < -2147483648)
	{
		write(2, "Error\n", 6);
		free_split(splitted);
		free(arr);
		return (1);
	}
	if (!isnum(splitted[x]))
	{
		write(2, "Error\n", 6);
		free_split(splitted);
		free(arr);
		return (1);
	}
	return (0);
}

int	check_and_sort(int *arr, int j, t_node *stack_a)
{
	t_node	*stack_b;

	stack_b = NULL;
	if (check_dup(arr, j))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	stack_a = fill(arr, j);
	if (issorted(stack_a))
	{
		free_stack(stack_a);
		return (1);
	}
	if (j < 6)
		mini_sort(&stack_a, j);
	else
		radix(arr, j, stack_b);
	free_stack(stack_a);
	return (0);
}

int	handle_arg(char **argv, int *arr, int j, int i)
{
	char	**splitted;
	int		x;
	long	num;

	splitted = ft_split(argv[i + 1], ' ');
	x = 0;
	if (!splitted)
		return (-1);
	while (splitted[x])
	{
		num = ft_atoi(splitted[x]);
		if (checks(num, splitted, arr, x))
			return (-1);
		arr[j++] = num;
		x++;
	}
	free_split(splitted);
	return (j);
}

int	main(int argc, char *argv[])
{
	int		*arr;
	int		i;
	int		j;
	t_node	*stack_a;

	stack_a = NULL;
	if (argc >= 2)
	{
		j = 0;
		i = 0;
		arr = malloc(sizeof(int) * 10000);
		if (!arr)
			return (1);
		while (i < argc - 1)
		{
			j = handle_arg(argv, arr, j, i);
			if (j == -1)
				{
					free(arr);
					return (1);
				}
			i++;
		}
		check_and_sort(arr, j, stack_a);
		free(arr);
	}
}
