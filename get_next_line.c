/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: musenov <musenov@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 19:35:37 by musenov           #+#    #+#             */
/*   Updated: 2023/05/28 11:37:32 by musenov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *remains, char *buffer)
{
	char			*array;
	unsigned int	size;
	int				i;
	int				j;

	if (!remains && !buffer)
		return (NULL);
	size = ft_strlen(remains) + ft_strlen(buffer);
	if (!(array = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	j = 0;
	if (remains)
	{
		while (remains[i])
			array[j++] = remains[i++];
		i = 0;
	}
	while (buffer[i])
		array[j++] = buffer[i++];
	array[size] = '\0';
	free((void *)remains);
	return (array);
}

char	*push_line(char *remains)
{
	int		i;
	char	*array;

	i = 0;
	while (remains[i] && remains[i] != '\n')
		i++;
	if (remains[i] == '\n')
		i++;
	if (!(array = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (remains[i] && remains[i] != '\n')
	{
		array[i] = remains[i];
		i++;
	}
	if (remains[i] == '\n')
	{
		array[i] = '\n';
		array[i + 1] = '\0';
		return (array);
	}
	array[i] = '\0';
	return (array);
}

char	*cut_next_line(char *remains)
{
	int		i;
	int		j;
	char	*array;

	i = 0;
	j = 0;
	while (remains[i] && remains[i] != '\n')
		i++;
	if (!remains[i])
	{
		free(remains);
		return (NULL);
	}
	if (!(array = (char *)malloc(sizeof(char) * (ft_strlen(remains) - i + 1))))
		return (NULL);
	i++;
	while (remains[i])
	{
		array[j] = remains[i];
		i++;
		j++;
	}
	array[j] = '\0';
	free(remains);
	return (array);
}

char	*get_next_line(int fd)
{
	static char	*remains;
	char		*line;
	int			count;
	char		buffer[BUFFER_SIZE + 1];

	if (fd < 0 || read(fd, NULL, 0) < 0 || BUFFER_SIZE <= 0)
		return (free(remains), remains = NULL, NULL);
	buffer[0] = '\0';
	count = 1;
	while (!ft_strchr(buffer) && count != 0)
	{
		if ((count = read(fd, buffer, BUFFER_SIZE)) == (-1))
			return (free(remains), remains = NULL, NULL);
		buffer[count] = '\0';
		remains = ft_strjoin(remains, buffer);
	}
	line = push_line(remains);
	remains = cut_next_line(remains);
	if (line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}
