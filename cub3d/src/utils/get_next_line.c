/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migumar2 <migumar2@student.42.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 17:06:38 by migumar2          #+#    #+#             */
/*   Updated: 2024/09/24 18:33:06 by migumar2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

#include "cub3d.h"

static char	*ft_joinandfree(char *storage, char *buffer)
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

static char	*create_storage(int fd, char *storage)
{
	char	*buffer;
	int		bytes_read;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
	{
		if (storage)
			free(storage);
		storage = NULL;
		return (NULL);
	}
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(storage, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (NULL);
		buffer[bytes_read] = 0;
		storage = ft_joinandfree(storage, buffer);
		if (!storage)
			return (NULL);
	}
	free(buffer);
	return (storage);
}

static char	*new_line(char *storage)
{
	char	*line;
	int		i;

	i = 0;
	if (!storage [i])
		return (NULL);
	while (storage[i] && storage[i] != '\n')
		i++;
	if (!storage[i])
		i--;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
	{
		return (NULL);
	}
	i = 0;
	while (storage[i] && storage[i] != '\n')
	{
		line[i] = storage[i];
		i++;
	}
	if (storage[i] && storage[i] == '\n')
		line[i] = '\n';
	return (line);
}

static char	*dlt_line(char *storage)
{
	char			*new_storage;
	unsigned long	i;
	int				j;

	j = 0;
	i = 0;
	if (!storage)
		return (NULL);
	while (storage[i] != 0 && storage[i] != '\n')
		i++;
	if (!storage[i])
	{
		free(storage);
		return (NULL);
	}
	new_storage = ft_calloc(ft_strlen(storage) - (i++) + 1, sizeof(char));
	if (!new_storage)
	{
		free(storage);
		return (NULL);
	}
	while (storage[i] != 0)
		new_storage[j++] = storage[i++];
	free (storage);
	return (new_storage);
}

char	*get_next_line(int fd)
{
	static char	*storage;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (storage)
		{
			free(storage);
			storage = NULL;
		}
		return (NULL);
	}
	storage = create_storage(fd, storage);
	if (!storage)
		return (NULL);
	line = new_line(storage);
	if (!line)
	{
		free(storage);
		storage = NULL;
	}
	else
		storage = dlt_line(storage);
	return (line);
}
