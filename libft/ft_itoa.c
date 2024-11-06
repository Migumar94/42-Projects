/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 19:26:30 by migumar2          #+#    #+#             */
/*   Updated: 2023/12/02 21:41:30 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_pwd(int n)
{
	int	num;

	num = 1;
	while (n > 0)
	{
		num *= 10;
		n--;
	}
	return (num);
}

int	ft_lennum(long num)
{
	int	size;

	size = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		size++;
		num = -num;
	}
	while (num > 0)
	{
		num = num / 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	long	num;
	char	*ptr;
	int		i;
	int		size;

	i = 0;
	num = n;
	size = ft_lennum(num);
	ptr = (char *)malloc(sizeof(char) * (size + 1));
	if (!ptr)
		return (NULL);
	if (num < 0)
	{
		ptr[0] = '-';
		i++;
		num = -num;
	}
	while (i < size)
	{
		ptr[i] = (num / ft_pwd(size - i - 1)) + '0';
		num = num % ft_pwd(size - i - 1);
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}
