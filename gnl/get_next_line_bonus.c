/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kassassi <kassassi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 13:16:00 by kassassi          #+#    #+#             */
/*   Updated: 2025/07/12 12:27:44 by kassassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line_bonus.h"

static char	*read_and_cat(int fd, char *stash)
{
	char	*buffer;
	char	*tmp;
	ssize_t	bytes;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (ft_find_nl(stash) == -1 && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(buffer);
			free(stash);
			return (NULL);
		}
		buffer[bytes] = '\0';
		tmp = ft_strjoin(stash, buffer);
		free(stash);
		stash = tmp;
	}
	free(buffer);
	return (stash);
}

static char	*extract_line(char **stash)
{
	char	*line;
	char	*rest;
	ssize_t	nl_pos;

	nl_pos = ft_find_nl(*stash);
	if (nl_pos >= 0)
	{
		line = ft_strndup(*stash, nl_pos + 1);
		rest = ft_strndup(*stash + nl_pos + 1, ft_strlen(*stash + nl_pos + 1));
		free(*stash);
		*stash = rest;
	}
	else
	{
		line = ft_strndup(*stash, ft_strlen(*stash));
		free(*stash);
		*stash = NULL;
	}
	if (line && *line == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stash[1024];
	char		*line;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	stash[fd] = read_and_cat(fd, stash[fd]);
	if (!stash[fd])
		return (NULL);
	line = extract_line(&stash[fd]);
	return (line);
}
