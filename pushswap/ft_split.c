/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 20:39:49 by migumar2          #+#    #+#             */
/*   Updated: 2024/03/07 14:11:53 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <stdio.h>

int	ft_countstr(char const *s, char c)
{
	int	size;
	int	i;

	i = 0;
	size = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			size++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (size);
}

char	**ft_clear(char ***ptr)
{
	int	i;

	if (ptr && *ptr)
	{
		i = 0;
		while ((*ptr)[i])
		{
			free((*ptr)[i]);
			(*ptr)[i] = NULL;
			i++;
		}
		free(*ptr);
		*ptr = NULL;
	}
	return (*ptr);
}

int	fill_split2(const char *s, int i, char c)
{
	int	j;

	j = 0;
	while (s[i + j] && s[i + j] != c)
		j++;
	return (j);
}

char	**fill_split(char **ptr, char const *s, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			j = fill_split2(s, i, c);
			if (j)
			{
				ptr[k] = ft_substr(s, i, j);
				if (!ptr[k++])
					return (ft_clear(&ptr));
				i += j;
			}
		}
		else
			i++;
	}
	ptr[k] = 0;
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	int		words;
	char	**ptr;

	if (!s)
		return (NULL);
	words = ft_countstr(s, c);
	ptr = malloc(sizeof(char *) * (words + 1));
	if (!ptr)
		return (NULL);
	ptr = fill_split(ptr, s, c);
	return (ptr);
}
