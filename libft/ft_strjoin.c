/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 17:18:37 by migumar2          #+#    #+#             */
/*   Updated: 2023/11/30 18:16:17 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	char	*ptr;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!size)
		size++;
	ptr = malloc(sizeof(char) * size);
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s1, size);
	ft_strlcat(ptr, s2, size);
	return (ptr);
}
