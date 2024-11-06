/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:44:57 by migumar2          #+#    #+#             */
/*   Updated: 2024/03/19 20:31:38 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strdup(char *s1)
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

char	**copy_map(char **map, int lines)
{
	char	**copy;
	int		i;

	copy = ft_calloc((lines + 1), sizeof (char *));
	if (!copy)
	{
		free(map);
		error();
	}
	i = 0;
	while (map[i])
	{
		copy[i] = ft_strdup(map[i]);
		i++;
	}
	return (copy);
}

int	check_ext(char *name)
{
	int	len;

	len = ft_strlen(name);
	if (name[len - 1] == 'r' && name[len - 2] == 'e'
		&& name[len - 3] == 'b' && name[len - 4] == '.')
		return (1);
	return (0);
}

void	put_spawn(t_map *t_map )
{
	int	i;
	int	j;

	i = 0;
	while (t_map->map[i])
	{
		j = 0;
		while (t_map->map[i][j])
		{
			if (t_map->map[i][j] == 'P')
			{
				t_map->actual_row = i;
				t_map->actual_column = j;
			}
			j++;
		}
		i++;
	}
}

void	count_coins(t_map *t_map)
{
	int	i;
	int	j;

	i = 0;
	while (t_map->map[i])
	{
		j = 0;
		while (t_map->map[i][j])
		{
			if (t_map->map[i][j] == 'C')
			{
				t_map->collects++;
			}
			j++;
		}
		i++;
	}
}
