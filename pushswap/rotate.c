/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:20:00 by migumar2          #+#    #+#             */
/*   Updated: 2024/03/10 18:38:01 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rotate_a(t_stack_node	**stack_a)
{
	t_stack_node	*first_node;
	t_stack_node	*second_node;

	if (*stack_a && (*stack_a)->next)
	{
		first_node = *stack_a;
		second_node = (*stack_a)->next;
		while ((*stack_a)->next)
			*stack_a = (*stack_a)->next;
		first_node->next = NULL;
		(*stack_a)->next = first_node;
		*stack_a = second_node;
	}
}

void	rotate_b(t_stack_node	**stack_b)
{
	t_stack_node	*first_node;
	t_stack_node	*second_node;

	if (*stack_b && (*stack_b)->next)
	{
		first_node = *stack_b;
		second_node = (*stack_b)->next;
		while ((*stack_b)->next)
			*stack_b = (*stack_b)->next;
		first_node->next = NULL;
		(*stack_b)->next = first_node;
		*stack_b = second_node;
	}
}

void	rotate_ab(t_stack_node	**stack_a, t_stack_node	**stack_b)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
}
