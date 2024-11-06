/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 18:29:52 by migumar2          #+#    #+#             */
/*   Updated: 2024/02/12 19:06:44 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	push_a(t_stack_node	**stack_a, t_stack_node	**stack_b)
{
	t_stack_node	*aux;

	if (*stack_b)
	{
		aux = *stack_b;
		*stack_b = (*stack_b)->next;
		aux->next = *stack_a;
		*stack_a = aux;
	}
}

void	push_b(t_stack_node	**stack_a, t_stack_node	**stack_b)
{
	t_stack_node	*aux;

	if (*stack_a)
	{
		aux = *stack_a;
		*stack_a = (*stack_a)->next;
		aux->next = *stack_b;
		*stack_b = aux;
	}
}
