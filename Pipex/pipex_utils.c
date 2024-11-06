/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:47:48 by migumar2          #+#    #+#             */
/*   Updated: 2024/04/09 18:53:42 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			size;
	char			*ptr;
	size_t			j;

	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if (start >= size)
		return (ft_strdup(""));
	else if (size - start < len)
		len = size - start;
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	j = 0;
	while (j < len && s[start + j])
	{
		ptr[j] = s[start + j];
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
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

char	*ft_strdup(const char *s1)
{
	char		*ptr;
	size_t		i;

	ptr = (char *) malloc (sizeof(char) * (ft_strlen(s1)+1));
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s1))
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

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
