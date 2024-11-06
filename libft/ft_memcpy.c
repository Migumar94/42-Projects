/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 21:09:52 by migumar2          #+#    #+#             */
/*   Updated: 2023/11/28 20:51:53 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dst_cpy;
	char	*src_cpy;

	dst_cpy = (char *) dst;
	src_cpy = (char *) src;
	i = 0;
	if (!dst && !src && n > 0)
		return (0);
	while (i < n)
	{
		dst_cpy[i] = src_cpy[i];
		i++;
	}
	dst = dst_cpy;
	return (dst);
}
