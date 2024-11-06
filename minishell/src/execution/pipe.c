/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholland <jholland@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 18:23:07 by migumar2          #+#    #+#             */
/*   Updated: 2024/07/15 18:28:22 by jholland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	create_pipe(t_token *l_token)
{
	pipe(l_token->fd);
	if (l_token->prev)
		l_token->prev->fd[1] = l_token->fd[1];
	if (l_token->next)
		l_token->next->fd[0] = l_token->fd[0];
}
