/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 21:41:20 by migumar2          #+#    #+#             */
/*   Updated: 2024/03/04 22:29:01 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	get_lower_position_index(t_stack_node *stack_a)
{
	int	lower_position;
	int	lower_index;

	lower_index = INT_MAX;
	lower_position = INT_MAX;
	while (stack_a)
	{
		if (stack_a->index <= lower_index)
		{
			lower_index = stack_a->index;
			lower_position = stack_a->pos;
		}
		stack_a = stack_a->next;
	}
	return (lower_position);
}

int	get_bigger_position_index(t_stack_node *stack_a)
{
	int	bigger_position;
	int	bigger_index;

	bigger_index = INT_MIN;
	bigger_position = INT_MAX;
	while (stack_a)
	{
		if (stack_a->index >= bigger_index)
		{
			bigger_index = stack_a->index;
			bigger_position = stack_a->pos;
		}
		stack_a = stack_a->next;
	}
	return (bigger_position);
}

void	set_target_stack(t_stack_node *stack_a, t_stack_node *stack_b)
{
	t_stack_node	*init_a;
	int				pos_big_lower;
	int				index_pos;

	init_a = stack_a;
	while (stack_b)
	{
		pos_big_lower = INT_MAX;
		index_pos = INT_MAX;
		stack_a = init_a;
		while (stack_a)
		{
			if (index_pos >= stack_a->index && stack_a->index > stack_b->index)
			{
				pos_big_lower = stack_a->pos;
				index_pos = stack_a->index;
			}
			stack_a = stack_a->next;
		}
		if (index_pos == INT_MAX)
			stack_b->target = get_bigger_position_index(stack_a);
		else
			stack_b->target = pos_big_lower;
		stack_b = stack_b->next;
	}
}
