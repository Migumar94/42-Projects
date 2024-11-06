/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 06:05:57 by migumar2          #+#    #+#             */
/*   Updated: 2024/03/05 19:44:53 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_node2(t_stack_node **stack_a,
				t_stack_node **stack_b, int cost_a, int cost_b)
{
	while (cost_a > 0)
	{
		ra(stack_a);
		cost_a--;
	}
	while (cost_b > 0)
	{
		rb(stack_b);
		cost_b--;
	}
	while (cost_a++ < 0)
		rra(stack_a);
	while (cost_b++ < 0)
		rrb(stack_b);
}

void	sort_node(t_stack_node **stack_a,
				t_stack_node **stack_b, int cost_a, int cost_b)
{
	while (cost_a > 0 && cost_b > 0)
	{
		rr(stack_a, stack_b);
		cost_a--;
		cost_b--;
	}
	while (cost_a < 0 && cost_b < 0)
	{
		rrr(stack_a, stack_b);
		cost_a++;
		cost_b++;
	}
	sort_node2(stack_a, stack_b, cost_a, cost_b);
	pa(stack_a, stack_b);
}

int	find_lower_index(t_stack_node *stack_a)
{
	int	pos;
	int	size;

	size = stack_size(stack_a);
	pos = 0;
	while (stack_a)
	{
		if (stack_a->index == 1)
			pos = stack_a->pos;
		stack_a = stack_a->next;
	}
	if (pos <= size / 2)
		return (pos);
	else
		return (pos - size);
}

void	last_sort(t_stack_node **stack_a, int cost)
{
	while (cost > 0)
	{
		ra(stack_a);
		cost--;
	}
	while (cost < 0)
	{
		rra(stack_a);
		cost++;
	}
}

void	sort_all(t_stack_node **stack_a, t_stack_node **stack_b)
{
	t_stack_node	*cheaper_node;
	int				cost_init;

	if (!ordered_stack(*stack_a))
	{
		push_all(stack_a, stack_b);
		sort_three(stack_a);
		while (*stack_b)
		{
			set_position(*stack_a);
			set_position(*stack_b);
			set_target_stack(*stack_a, *stack_b);
			set_cost(*stack_a, *stack_b);
			cheaper_node = find_cheaper(*stack_b, NULL, INT_MAX);
			sort_node(stack_a, stack_b, cheaper_node->cost_a,
				cheaper_node->cost_b);
		}
		set_position(*stack_a);
		cost_init = find_lower_index(*stack_a);
		last_sort(stack_a, cost_init);
	}
}
