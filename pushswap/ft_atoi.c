/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 15:05:57 by migumar2          #+#    #+#             */
/*   Updated: 2024/03/04 20:17:40 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_atoi(char *str, int *list)
{
	long	num;
	int		i;
	int		sign;

	sign = 1;
	num = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign *= -1;
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			error(list, NULL);
		num *= 10;
		num += (str[i++] - 48);
	}
	if ((sign * num) < INT_MIN || (sign * num) > INT_MAX)
		error(list, NULL);
	return (num * sign);
}
