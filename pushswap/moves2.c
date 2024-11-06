/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 00:07:26 by migumar2          #+#    #+#             */
/*   Updated: 2024/03/05 19:42:10 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ra(t_stack_node	**stack_a)
{
	rotate_a(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_stack_node	**stack_b)
{
	rotate_b(stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_stack_node	**stack_a, t_stack_node	**stack_b)
{
	rotate_ab(stack_a, stack_b);
	write(1, "rr\n", 3);
}

void	rra(t_stack_node	**stack_a)
{
	re_rotate_a(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack_node	**stack_b)
{
	re_rotate_b(stack_b);
	write(1, "rrb\n", 4);
}
