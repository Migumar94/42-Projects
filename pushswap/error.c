/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:21:26 by migumar2          #+#    #+#             */
/*   Updated: 2024/03/07 16:30:35 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	error(int *list, char **str)
{
	int	i;

	i = 0;
	if (list)
		free(list);
	if (str)
	{
		while (str[i])
			free(str[i++]);
		free(str);
	}
	write(2, "Error\n", 6);
	exit(1);
}
