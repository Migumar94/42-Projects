/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 23:41:52 by migumar2          #+#    #+#             */
/*   Updated: 2024/03/06 19:39:44 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	set_position(t_stack_node *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack->pos = i;
		stack = stack->next;
		i++;
	}
}

void	set_index(t_stack_node *stack_a, int stack_size)
{
	t_stack_node	*ptr;
	t_stack_node	*biggest;
	int				bigger_value;

	while (stack_size > 0)
	{
		ptr = stack_a;
		bigger_value = INT_MIN;
		biggest = NULL;
		while (ptr)
		{
			if (ptr->value == INT_MIN)
				ptr->index = 1;
			if (ptr->value >= bigger_value && ptr->index == 0)
			{
				bigger_value = ptr->value;
				biggest = ptr;
			}
			ptr = ptr->next;
		}
		if (biggest)
			biggest->index = stack_size;
		stack_size--;
	}
}

void	complete_stack(t_stack_node *initial_stack, int size)
{
	set_position(initial_stack);
	set_index(initial_stack, size);
}

int	set_defaults(int i, int *list, t_stack_node	**current_stack,
			t_stack_node	*new_node)
{
	new_node->value = list[i];
	new_node->pos = i;
	new_node->index = 0;
	(*current_stack)->next = new_node;
	*current_stack = new_node;
	i++;
	return (i);
}

t_stack_node	*createstack(int *list, int size)
{
	t_stack_node	*current_stack;
	t_stack_node	*initial_stack;
	t_stack_node	*new_node;
	int				i;

	initial_stack = malloc(sizeof(t_stack_node) * 1);
	current_stack = initial_stack;
	new_node = initial_stack;
	i = 0;
	while (i < size)
	{
		if (i != 0)
			new_node = malloc(sizeof(t_stack_node) * 1);
		if (!new_node)
		{
			free_list(&initial_stack);
			error(list, NULL);
		}
		i = set_defaults(i, list, &current_stack, new_node);
	}
	new_node->next = NULL;
	complete_stack(initial_stack, size);
	free(list);
	return (initial_stack);
}
