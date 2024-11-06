/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 01:45:17 by migumar2          #+#    #+#             */
/*   Updated: 2024/03/10 14:43:14 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	free_list(t_stack_node	**stack_a)
{
	t_stack_node	*tmp;

	while (*stack_a)
	{
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		free(tmp);
	}
}

void	free_pointer(char **pointer)
{
	char	*aux;
	int		i;

	i = 0;
	while (pointer[i])
	{
		aux = pointer[i];
		i++;
		if (aux)
			free(aux);
	}
	if (pointer)
		free(pointer);
}
