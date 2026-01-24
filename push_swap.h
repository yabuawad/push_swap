/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabuawad <yabuawad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 14:11:24 by yabuawad          #+#    #+#             */
/*   Updated: 2025/11/17 15:15:31 by yabuawad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct node
{
	int			data;
	struct node	*next;
}				t_node;

void			make_stack(t_node **stack, int value);
t_node			*fill(int *arr, int argc);

// operations
void			swap(t_node **top);
void			push_node(t_node **src, t_node **dst);
void			rotate(t_node **stack);
void			rev_rot(t_node **stack);

// helper functions
int				list_size(t_node *top);
t_node			*lstlast(t_node *top);
int				check_dup(int *arr, int size);
int				isnum(char *str);
long			ft_atoi(char *str);

// to test
void			print_stack(t_node *stack);
char			**ft_split(char const *s, char c);
void			free_split(char **arr);
void			free_stack(t_node *stack_a);

// sort
void			mini_sort(t_node **stack_a, int num);
void			radix(int *arr, int size, t_node *stack_b);
int				issorted(t_node *stack_a);
void			bub_sort_ext(int size, int *sorted, int *arr);
void			sort_three_ext(t_node **stack_a, int first, int second,
					int third);
void			sort_five_ext(t_node **stack_a, int min_ind);
void			sort_four_ext(int min_index, t_node **stack_a);
#endif