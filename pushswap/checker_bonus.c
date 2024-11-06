/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 21:29:23 by migumar2          #+#    #+#             */
/*   Updated: 2024/03/10 18:50:05 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i] || s1[i] == '\0' || s2[i] == '\0')
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	return (0);
}

void	free_and_exit(char *move, t_stack_node **stack_a,
		t_stack_node **stack_b)
{
	if (ft_strncmp(move, "\n", 1))
	{
		free_list(stack_a);
		free_list(stack_b);
		free(move);
		error(NULL, NULL);
	}
}

void	more_moves(char *move, t_stack_node **stack_a, t_stack_node **stack_b)
{
	if (!ft_strncmp(move, "sa\n", 3))
		swap_a(stack_a);
	else if (!ft_strncmp(move, "sb\n", 3))
		swap_a(stack_b);
	else if (!ft_strncmp(move, "ss\n", 3))
		swap_ab(stack_a, stack_b);
	else if (!ft_strncmp(move, "pa\n", 3))
		push_a(stack_a, stack_b);
	else if (!ft_strncmp(move, "pb\n", 3))
		push_b(stack_a, stack_b);
	else if (!ft_strncmp(move, "ra\n", 3))
		rotate_a(stack_a);
	else if (!ft_strncmp(move, "rb\n", 3))
		rotate_b(stack_b);
	else if (!ft_strncmp(move, "rr\n", 3))
		rotate_ab(stack_a, stack_b);
	else if (!ft_strncmp(move, "rra\n", 4))
		re_rotate_a(stack_a);
	else if (!ft_strncmp(move, "rrb\n", 4))
		re_rotate_b(stack_b);
	else if (!ft_strncmp(move, "rrr\n", 4))
		re_rotate_ab(stack_a, stack_b);
	else
		free_and_exit(move, stack_a, stack_b);
}

void	read_and_move(t_stack_node **stack_a, t_stack_node **stack_b)
{
	char	*move;

	move = get_next_line(0);
	while (move != NULL)
	{
		more_moves(move, stack_a, stack_b);
		free(move);
		move = get_next_line(0);
	}
	free(move);
}

int	main(int argc, char **argv)
{
	t_stack_node	*stack_a;
	t_stack_node	*stack_b;

	stack_a = check_argument(argc, argv);
	complete_stack(stack_a, stack_size(stack_a));
	stack_b = NULL;
	if (!stack_a)
		return (0);
	read_and_move(&stack_a, &stack_b);
	if (stack_b == NULL && ordered_stack(stack_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_list(&stack_a);
	free_list(&stack_b);
}
