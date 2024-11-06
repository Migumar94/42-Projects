/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 17:09:34 by migumar2          #+#    #+#             */
/*   Updated: 2024/04/16 14:05:21 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(char *comand)
{
	write(2, "pipex: ", 7);
	write(2, comand, ft_strlen(comand));
	write(2, ": ", 2);
	write(2, "command not found\n", 18);
}
