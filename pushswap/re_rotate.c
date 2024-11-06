/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 23:37:54 by migumar2          #+#    #+#             */
/*   Updated: 2024/03/05 16:53:47 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	re_rotate_a(t_stack_node	**stack_a)
{
	t_stack_node	*first_node;
	t_stack_node	*last_node;

	if (*stack_a && (*stack_a)->next)
	{
		first_node = *stack_a;
		while ((*stack_a)->next)
		{
			last_node = *stack_a;
			*stack_a = (*stack_a)->next;
		}
		(*stack_a)->next = first_node;
		*stack_a = last_node->next;
		last_node->next = NULL;
	}
}

void	re_rotate_b(t_stack_node	**stack_b)
{
	t_stack_node	*first_node;
	t_stack_node	*last_node;

	if (*stack_b && (*stack_b)->next)
	{
		first_node = *stack_b;
		while ((*stack_b)->next)
		{
			last_node = *stack_b;
			*stack_b = (*stack_b)->next;
		}
		(*stack_b)->next = first_node;
		*stack_b = last_node->next;
		last_node->next = NULL;
	}
}

void	re_rotate_ab(t_stack_node	**stack_a, t_stack_node	**stack_b)
{
	re_rotate_a(stack_a);
	re_rotate_b(stack_b);
}
