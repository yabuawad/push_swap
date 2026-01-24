/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_mini.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabuawad <yabuawad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 15:37:56 by yabuawad          #+#    #+#             */
/*   Updated: 2025/11/17 15:13:00 by yabuawad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min(t_node **stack_a)
{
	int		min;
	int		ind;
	int		ind_min;
	t_node	*temp;

	min = (*stack_a)->data;
	ind = 0;
	ind_min = 0;
	temp = *stack_a;
	while (temp != NULL)
	{
		if (temp->data < min)
		{
			min = temp->data;
			ind_min = ind;
		}
		temp = temp->next;
		ind++;
	}
	return (ind_min);
}

static void	sort_three(t_node **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->data;
	second = (*stack_a)->next->data;
	third = (*stack_a)->next->next->data;
	if (first > second && third > first && second < third)
	{
		swap(stack_a);
		write(1, "sa\n", 3);
	}
	sort_three_ext(stack_a, first, second, third);
}

static void	sort_four(t_node **stack_a)
{
	int		min_index;
	t_node	*stack_b;

	min_index = find_min(stack_a);
	stack_b = NULL;
	sort_four_ext(min_index, stack_a);
	push_node(stack_a, &stack_b);
	write(1, "pb\n", 3);
	sort_three(stack_a);
	push_node(&stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	sort_five(t_node **stack_a)
{
	int		min_ind;
	t_node	*stack_b;

	min_ind = find_min(stack_a);
	stack_b = NULL;
	sort_five_ext(stack_a, min_ind);
	push_node(stack_a, &stack_b);
	write(1, "pb\n", 3);
	sort_four(stack_a);
	push_node(&stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	mini_sort(t_node **stack_a, int num)
{
	if (num == 2)
	{
		if (((*stack_a)->next) > ((*stack_a)->next->next))
		{
			swap(stack_a);
			write(1, "sa\n", 3);
		}
		else
			return ;
	}
	if (num == 3)
	{
		sort_three(stack_a);
	}
	else if (num == 4)
	{
		sort_four(stack_a);
	}
	if (num == 5)
	{
		sort_five(stack_a);
	}
}
