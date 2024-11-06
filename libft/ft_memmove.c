/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:09:38 by migumar2          #+#    #+#             */
/*   Updated: 2023/11/28 20:58:34 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*ptr_dst;
	char	*ptr_src;
	int		j;

	ptr_src = (char *) src;
	ptr_dst = (char *) dst;
	if (!dst && !src && len > 0)
		return (0);
	if (dst > src)
	{
		j = (int) len--;
		while (j-- > 0)
			ptr_dst[j] = ptr_src[j];
	}
	else
	{
		j = -1;
		while (j++ < (int) len - 1)
			ptr_dst[j] = ptr_src[j];
	}
	return (dst);
}
