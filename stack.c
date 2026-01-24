/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabuawad <yabuawad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 14:11:05 by yabuawad          #+#    #+#             */
/*   Updated: 2025/11/17 15:22:34 by yabuawad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_stack(t_node **stack, int value) // create stack+fill
{
	t_node	*newnode;

	newnode = malloc(sizeof(t_node));
	if(!newnode)
	return;
	newnode->data = value;
	newnode->next = *stack;
	*stack = newnode;
}

t_node	*fill(int *arr, int argc)
{
	t_node	*stack_a;
	int		i;

	stack_a = NULL;
	i = argc - 1;
	while (i >= 0)
	{
		make_stack(&stack_a, arr[i]);
		i--;
	}
	return (stack_a);
}

void	free_stack(t_node *stack_a)
{
	t_node	*temp;

	while (stack_a)
	{
		temp = stack_a->next;
		free(stack_a);
		stack_a = temp;
	}
}
