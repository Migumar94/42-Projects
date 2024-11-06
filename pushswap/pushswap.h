/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 19:44:06 by migumar2          #+#    #+#             */
/*   Updated: 2024/03/07 13:20:35 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_stack_node
{
	int					value;
	int					index;
	int					pos;
	int					target;
	int					cost_a;
	int					cost_b;
	struct s_stack_node	*next;
}					t_stack_node;

char			**ft_split(char const *s, char c);
int				ft_atoi(char *str, int *list);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strdup(const char *s1);
size_t			ft_strlen(const char *str);
void			error(int *list, char **str);
t_stack_node	*check_argument(int argc, char **argv);
void			check_repeat(int *list, int size);
t_stack_node	*createstack(int *list, int size);
int				stack_size(t_stack_node *stack);
int				ordered_stack(t_stack_node *stack);
void			complete_stack(t_stack_node *initial_stack, int size);
void			swap_a(t_stack_node	**stack_a);
void			swap_b(t_stack_node	**stack_b);
void			swap_ab(t_stack_node	**stack_a, t_stack_node	**stack_b);
void			push_a(t_stack_node	**stack_a, t_stack_node	**stack_b);
void			push_b(t_stack_node	**stack_a, t_stack_node	**stack_b);
void			rotate_a(t_stack_node	**stack_a);
void			rotate_b(t_stack_node	**stack_b);
void			rotate_ab(t_stack_node	**stack_a, t_stack_node	**stack_b);
void			re_rotate_a(t_stack_node	**stack_a);
void			re_rotate_b(t_stack_node	**stack_b);
void			re_rotate_ab(t_stack_node	**stack_a, t_stack_node	**stack_b);
int				get_biggest_index(t_stack_node *stack);
void			sort_three(t_stack_node	**stack_a);
void			sort_all(t_stack_node **stack_a, t_stack_node **stack_b);
void			set_target_stack(t_stack_node *stack_a, t_stack_node *stack_b);
void			set_position(t_stack_node *stack);
void			set_cost(t_stack_node *stack_a, t_stack_node *stack_b);
t_stack_node	*find_cheaper(t_stack_node *stack_b, t_stack_node *c_n, int c);
void			sa(t_stack_node	**stack_a);
void			sb(t_stack_node	**stack_b);
void			ss(t_stack_node	**stack_a, t_stack_node	**stack_b);
void			pa(t_stack_node	**stack_a, t_stack_node	**stack_b);
void			pb(t_stack_node	**stack_a, t_stack_node	**stack_b);
void			ra(t_stack_node	**stack_a);
void			rb(t_stack_node	**stack_b);
void			rr(t_stack_node	**stack_a, t_stack_node	**stack_b);
void			rra(t_stack_node	**stack_a);
void			rrb(t_stack_node	**stack_b);
void			rrr(t_stack_node	**stack_a, t_stack_node	**stack_b);
void			free_list(t_stack_node	**stack_a);
void			push_all(t_stack_node **stack_a, t_stack_node **stack_b);
int				ft_abs(int n);
char			*get_next_line(int fd);
void			*ft_calloc(size_t count, size_t size);
size_t			ft_strlen(const char *str);
char			*ft_joinandfree(char *storage, char *buffer);
char			*ft_strchr(char *str, char c);
void			free_pointer(char **pointer);
#endif