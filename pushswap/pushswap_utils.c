/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 00:34:07 by migumar2          #+#    #+#             */
/*   Updated: 2024/03/06 19:32:06 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	stack_size(t_stack_node *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

int	ordered_stack(t_stack_node *stack)
{
	int	num;

	num = stack->value;
	while (stack)
	{
		if (stack->value < num)
			return (0);
		num = stack ->value;
		stack = stack->next;
	}
	return (1);
}

int	get_biggest_index(t_stack_node *stack)
{
	int	biggest_index;

	biggest_index = 0;
	while (stack)
	{
		if (biggest_index <= stack->index)
			biggest_index = stack->index;
		stack = stack->next;
	}
	return (biggest_index);
}

void	push_all(t_stack_node **stack_a, t_stack_node **stack_b)
{
	int	size;

	size = stack_size(*stack_a);
	while (stack_size(*stack_a) > 3)
	{
		if ((*stack_a)->index > size - 3)
			ra(stack_a);
		else
			pb(stack_a, stack_b);
	}
}

int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}
