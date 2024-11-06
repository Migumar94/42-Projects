/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 00:29:59 by migumar2          #+#    #+#             */
/*   Updated: 2024/03/05 14:13:40 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	set_cost(t_stack_node *stack_a, t_stack_node *stack_b)
{
	int	size_b;

	size_b = stack_size(stack_b);
	while (stack_b)
	{
		if (stack_b->pos > size_b / 2)
			stack_b->cost_b = stack_b->pos - size_b;
		else
			stack_b->cost_b = stack_b->pos;
		if (stack_b->target > stack_size(stack_a) / 2)
			stack_b->cost_a = stack_b->target - stack_size(stack_a);
		else
			stack_b->cost_a = stack_b->target;
		stack_b = stack_b->next;
	}
}

t_stack_node	*find_cheaper(t_stack_node *stack_b, t_stack_node *c_n, int c_c)
{
	while (stack_b)
	{
		if ((stack_b->cost_a < 0 && stack_b->cost_b < 0)
			|| (stack_b->cost_a > 0 && stack_b->cost_b > 0))
		{
			if (ft_abs(stack_b->cost_a) < c_c && ft_abs(stack_b->cost_b) < c_c)
			{
				if (ft_abs(stack_b->cost_a) < ft_abs(stack_b->cost_b))
					c_c = ft_abs(stack_b->cost_b);
				else
					c_c = ft_abs(stack_b->cost_a);
				c_n = stack_b;
			}
		}
		else if (ft_abs(stack_b->cost_a) + ft_abs(stack_b->cost_b) < c_c)
		{
			c_c = ft_abs(stack_b->cost_a) + ft_abs(stack_b->cost_b);
			c_n = stack_b;
		}
		stack_b = stack_b->next;
	}
	return (c_n);
}
