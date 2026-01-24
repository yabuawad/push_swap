/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabuawad <yabuawad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 14:51:57 by yabuawad          #+#    #+#             */
/*   Updated: 2025/11/17 15:13:56 by yabuawad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_five_ext(t_node **stack_a, int min_ind)
{
	if (min_ind == 1)
	{
		swap(stack_a);
		write(1, "sa\n", 3);
	}
	if (min_ind == 2)
	{
		rotate(stack_a);
		write(1, "ra\n", 3);
		rotate(stack_a);
		write(1, "ra\n", 3);
	}
	if (min_ind == 3)
	{
		rev_rot(stack_a);
		write(1, "rra\n", 4);
		rev_rot(stack_a);
		write(1, "rra\n", 4);
	}
	if (min_ind == 4)
	{
		rev_rot(stack_a);
		write(1, "rra\n", 4);
	}
}

void	sort_three_ext(t_node **stack_a, int first, int second, int third)
{
	if (first > second && second > third && first > third)
	{
		swap(stack_a);
		write(1, "sa\n", 3);
		rev_rot(stack_a);
		write(1, "rra\n", 4);
	}
	else if (first < second && second > third && first < third)
	{
		swap(stack_a);
		write(1, "sa\n", 3);
		rotate(stack_a);
		write(1, "ra\n", 3);
	}
	else if (first > second && second < third && first > third)
	{
		rotate(stack_a);
		write(1, "ra\n", 3);
	}
	else if (first < second && second > third && first > third)
	{
		rev_rot(stack_a);
		write(1, "rra\n", 4);
	}
}

void	sort_four_ext(int min_index, t_node **stack_a)
{
	if (min_index == 1)
	{
		swap(stack_a);
		write(1, "sa\n", 3);
	}
	if (min_index == 2)
	{
		rev_rot(stack_a);
		write(1, "rra\n", 4);
		rev_rot(stack_a);
		write(1, "rra\n", 4);
	}
	if (min_index == 3)
	{
		rev_rot(stack_a);
		write(1, "rra\n", 4);
	}
}

void	bub_sort_ext(int size, int *sorted, int *arr)
{
	int	i;

	i = 0;
	while (i < size)
	{
		sorted[i] = arr[i];
		i++;
	}
}
