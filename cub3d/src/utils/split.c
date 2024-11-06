/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jholland <jholland@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 16:40:39 by migumar2          #+#    #+#             */
/*   Updated: 2024/09/23 18:00:55 by jholland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

unsigned int	ft_countstr(char const *s, char c)
{
	unsigned int	size;
	unsigned int	i;

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
	unsigned int	str_count;
	char			**ptr;

	if (!s)
		return (NULL);
	str_count = ft_countstr(s, c);
	ptr = malloc(sizeof(char *) * (str_count + 1));
	if (!ptr)
		return (NULL);
	ptr = fill_split(ptr, s, c);
	return (ptr);
}
