/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checklist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 01:03:31 by migumar2          #+#    #+#             */
/*   Updated: 2024/03/10 18:43:01 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	*atoi_all(char **argv, int *size)
{
	int	*list;

	*size = 0;
	while (argv[*size])
		(*size)++;
	list = (int *)malloc(sizeof(int) * (*size));
	if (!list)
		return (NULL);
	*size = 0;
	while (argv[*size])
	{
		list[*size] = ft_atoi(argv[*size], list);
		(*size)++;
	}
	return (list);
}

void	check_repeat(int *list, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (list[i] == list[j])
				error(list, NULL);
			j++;
		}
		i++;
	}
}

t_stack_node	*check_argument(int argc, char **argv)
{
	int				*list;
	char			**tmp;
	int				size;

	list = NULL;
	size = 0;
	if (argc < 2)
		return (NULL);
	else if (argc == 2)
	{
		tmp = ft_split(argv[1], ' ');
		list = atoi_all(tmp, &size);
		free_pointer(tmp);
		if (!list[0])
			error(list, NULL);
	}
	else
	{
		list = atoi_all(argv + 1, &size);
	}
	check_repeat(list, size);
	return (createstack(list, size));
}
