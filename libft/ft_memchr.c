/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:51:04 by migumar2          #+#    #+#             */
/*   Updated: 2023/11/28 21:58:11 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptr;
	unsigned char	aux;

	ptr = (unsigned char *) str;
	aux = (unsigned char) c;
	i = 0;
	if (n <= 0)
		return (0);
	while (i < n)
	{
		if (ptr[i] == aux)
			return ((void *) &ptr[i]);
		i++;
	}
	return (NULL);
}
