/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_extras.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 21:51:10 by migumar2          #+#    #+#             */
/*   Updated: 2024/04/16 15:11:12 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_list(char **paths)
{
	int	i;

	i = 0;
	while (paths[i])
	{
		free(paths[i]);
		i++;
	}
	free(paths);
}

char	**ft_spliter(char *str)
{
	char	**aux1;
	char	**aux2;
	char	**ret;

	if (str[0] == '.')
	{
		aux1 = ft_calloc(2, sizeof(char *));
		aux1[0] = str;
	}
	else if (!quote_is_after(str))
	{
		if (ft_strrchr(str, '\''))
			aux1 = ft_split(str, '\'');
		else
			aux1 = ft_split(str, '"');
	}
	else
		aux1 = ft_split(str, '"');
	aux2 = ft_split(aux1[0], ' ');
	if (str[0] == '.')
		return (aux2);
	ret = join_comand(aux2, aux1[1]);
	return (ret);
}

char	**join_comand(char **str1, char *str2)
{
	int		i;
	char	**ret;

	i = 0;
	while (str1[i])
		i++;
	ret = malloc (sizeof(char *) * (i + 2));
	if (!ret)
		return (NULL);
	i = 0;
	while (str1[i])
	{
		ret[i] = str1[i];
		i++;
	}
	ret[i] = str2;
	ret[i + 1] = NULL;
	return (ret);
}

int	quote_is_after(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '"')
			return (1);
		if (str[i] == '\'')
			return (0);
		i++;
	}
	return (0);
}

char	*delete_slash(char *str)
{
	char	**aux;
	char	*ret;
	int		i;

	ret = NULL;
	aux = ft_split(str, '\\');
	i = 0;
	while (aux[i])
	{
		ret = ft_strjoin(ret, aux[i]);
		i++;
	}
	free_list(aux);
	return (ret);
}
