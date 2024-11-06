/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 00:09:54 by migumar2          #+#    #+#             */
/*   Updated: 2024/02/22 22:40:40 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	rrr(t_stack_node	**stack_a, t_stack_node	**stack_b)
{
	re_rotate_ab(stack_a, stack_b);
	write(1, "rrr\n", 4);
}
