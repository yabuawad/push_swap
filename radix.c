/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabuawad <yabuawad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 14:51:20 by yabuawad          #+#    #+#             */
/*   Updated: 2025/11/17 15:10:35 by yabuawad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*bub_sort(int *arr, int size)
{
	int	*sorted;
	int	x;
	int	j;
	int	temp;

	sorted = malloc(size * sizeof(int));
	x = 0;
	bub_sort_ext(size, sorted, arr);
	while (x < size - 1)
	{
		j = 0;
		while (j < size - x - 1)
		{
			if (sorted[j] > sorted[j + 1])
			{
				temp = sorted[j];
				sorted[j] = sorted[j + 1];
				sorted[j + 1] = temp;
			}
			j++;
		}
		x++;
	}
	return (sorted);
}

static void	rank(int *arr, int size)
{
	int	*sorted;
	int	i;
	int	x;

	sorted = bub_sort(arr, size);
	i = 0;
	if (!sorted)
		return ;
	while (i < size)
	{
		x = 0;
		while (x < size)
		{
			if (arr[i] == sorted[x])
			{
				arr[i] = x;
				break ;
			}
			x++;
		}
		i++;
	}
	free(sorted);
}

int	find_max(int *arr, int size)
{
	int	max_bit;
	int	i;

	i = 0;
	max_bit = arr[0];
	while (i < size)
	{
		if (arr[i] > max_bit)
			max_bit = arr[i];
		i++;
	}
	return (max_bit);
}

void	radix_ext(t_node **ranked_stack, t_node **stack_b, int size, int i)
{
	int	j;

	j = 0;
	while (j < size)
	{
		if ((((*ranked_stack)->data >> i) & 1) == 0)
		{
			push_node(ranked_stack, stack_b);
			write(1, "pb\n", 3);
		}
		else
		{
			rotate(ranked_stack);
			write(1, "ra\n", 3);
		}
		j++;
	}
	while (*stack_b != NULL)
	{
		push_node(stack_b, ranked_stack);
		write(1, "pa\n", 3);
	}
}

void	radix(int *arr, int size, t_node *stack_b)
{
	t_node	*ranked_stack;
	int		max_bit;
	int		bit;
	int		i;

	rank(arr, size);
	ranked_stack = fill(arr, size);
	if (!ranked_stack)
		return ;
	if (issorted(ranked_stack))
	{
		free_stack(ranked_stack);
		return ;
	}
	bit = 0;
	i = 0;
	max_bit = find_max(arr, size);
	while ((max_bit >> bit) != 0)
		bit++;
	while (i < bit)
	{
		radix_ext(&ranked_stack, &stack_b, size, i);
		i++;
	}
	free_stack(ranked_stack);
}
