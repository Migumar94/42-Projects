/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 04:55:34 by migumar2          #+#    #+#             */
/*   Updated: 2024/03/05 19:45:27 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_three(t_stack_node	**stack_a)
{
	if (!ordered_stack(*stack_a))
	{
		if ((*stack_a)->index == get_biggest_index(*stack_a))
			ra(stack_a);
		else if ((*stack_a)->next->index == get_biggest_index(*stack_a))
			rra(stack_a);
		if ((*stack_a)->index > (*stack_a)->next->index)
			sa(stack_a);
	}
}
