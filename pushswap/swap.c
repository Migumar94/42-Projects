/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:24:02 by migumar2          #+#    #+#             */
/*   Updated: 2024/03/10 18:45:36 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	swap_a(t_stack_node	**stack_a)
{
	t_stack_node	*aux;

	aux = *stack_a;
	if (*stack_a && (*stack_a)->next)
	{
		*stack_a = (*stack_a)->next;
		aux->next = (*stack_a)->next;
		(*stack_a)->next = aux;
	}
}

void	swap_b(t_stack_node	**stack_b)
{
	t_stack_node	*aux;

	aux = *stack_b;
	if (*stack_b && (*stack_b)->next)
	{
		*stack_b = (*stack_b)->next;
		aux->next = (*stack_b)->next;
		(*stack_b)->next = aux;
	}
}

void	swap_ab(t_stack_node	**stack_a, t_stack_node	**stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
}
