/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 19:24:16 by migumar2          #+#    #+#             */
/*   Updated: 2024/01/14 21:47:18 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	char		*ptr;
	size_t		i;

	ptr = (char *) malloc (size * count);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < (count * size))
	{
		ptr[i] = 0;
		i++;
	}
	return ((void *)ptr);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (&str[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	j = -1;
	if (!s1)
		s1 = ft_calloc(1, 1);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!size)
		size++;
	ptr = malloc(sizeof(char) * size);
	if (!ptr)
		return (NULL);
	while (s1[i] != 0)
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[++j] != 0)
		ptr[i + j] = s2[j];
	ptr[i + j] = 0;
	return (ptr);
}

char	*ft_joinandfree(char *storage, char *buffer)
{
	char	*tmp;

	if (!storage)
		storage = ft_calloc(1, 1);
	if (!storage)
	{
		free(buffer);
		return (NULL);
	}
	tmp = ft_strjoin(storage, buffer);
	if (!tmp)
	{
		free(buffer);
		free(storage);
		return (NULL);
	}
	free(storage);
	return (tmp);
}
