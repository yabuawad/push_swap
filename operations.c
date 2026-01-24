/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabuawad <yabuawad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 13:56:40 by yabuawad          #+#    #+#             */
/*   Updated: 2025/11/17 15:11:58 by yabuawad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node **top)
{
	t_node	*first;
	t_node	*second;

	if (list_size(*top) >= 2)
	{
		first = *top;
		second = first->next;
		first->next = second->next;
		second->next = first;
		*top = second;
	}
}

void	push_node(t_node **src, t_node **dst)
{
	t_node	*temp;

	if (*src != NULL)
	{
		temp = NULL;
		temp = *src;
		*src = (*src)->next;
		temp->next = *dst;
		*dst = temp;
	}
}

void	rotate(t_node **stack)
{
	t_node	*first;
	t_node	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	last = lstlast(*stack);
	*stack = first->next;
	last->next = first;
	first->next = NULL;
}

void	rev_rot(t_node **stack)
{
	t_node	*last;
	t_node	*prelast;

	if (!*stack || (*stack)->next == NULL)
		return ;
	last = *stack;
	prelast = NULL;
	while (last->next != NULL)
	{
		prelast = last;
		last = last->next;
	}
	prelast->next = NULL;
	last->next = *stack;
	*stack = last;
}
