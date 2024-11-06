/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 00:01:25 by migumar2          #+#    #+#             */
/*   Updated: 2024/03/05 19:18:18 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sa(t_stack_node	**stack_a)
{
	swap_a(stack_a);
	write(1, "sa\n", 3);
}

void	sb(t_stack_node	**stack_b)
{
	swap_b(stack_b);
	write(1, "sb\n", 3);
}

void	ss(t_stack_node	**stack_a, t_stack_node	**stack_b)
{
	swap_ab(stack_a, stack_b);
	write(1, "ss\n", 3);
}

void	pa(t_stack_node	**stack_a, t_stack_node	**stack_b)
{
	push_a(stack_a, stack_b);
	write(1, "pa\n", 3);
}

void	pb(t_stack_node	**stack_a, t_stack_node	**stack_b)
{
	push_b(stack_a, stack_b);
	write(1, "pb\n", 3);
}
