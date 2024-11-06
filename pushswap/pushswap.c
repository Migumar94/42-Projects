/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:50:40 by migumar2          #+#    #+#             */
/*   Updated: 2024/03/10 18:43:58 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;

	stack_a = check_argument(argc, argv);
	if (!stack_a)
		return (0);
	complete_stack(stack_a, stack_size(stack_a));
	stack_b = NULL;
	if (stack_size(stack_a) <= 3)
		sort_three(&stack_a);
	if (stack_size(stack_a) > 3)
		sort_all(&stack_a, &stack_b);
	free_list(&stack_a);
	return (0);
}
