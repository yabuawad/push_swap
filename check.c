/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabuawad <yabuawad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 14:53:27 by yabuawad          #+#    #+#             */
/*   Updated: 2025/11/17 15:16:22 by yabuawad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// a function that checks if things are already sorted
int	issorted(t_node *stack_a)
{
	if (!stack_a)
		return (1);
	while (stack_a != NULL && stack_a->next)
	{
		if ((stack_a->data) > (stack_a->next->data))
			return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

//& a free function for my split when it fails
void	free_split(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
