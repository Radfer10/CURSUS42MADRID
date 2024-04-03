/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 23:55:50 by rde-migu          #+#    #+#             */
/*   Updated: 2024/04/02 19:05:03 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_read(int fd, char *buf, char **buffer)
{
	char	*temp;
	int		readbytes;

	readbytes = 1;
	if (ft_strchr(*buffer, '\n'))
		return ;
	while (readbytes > 0)
	{
		readbytes = read(fd, buf, BUFFER_SIZE);
		if (readbytes == -1 || readbytes == 0)
			return ;
		buf[readbytes] = '\0';
		temp = ft_strjoin(*buffer, buf);
		free(*buffer);
		*buffer = temp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
}

char	*ft_read_text(int fd, char *buffer)
{
	char	*buf;

	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
	{
		free(buffer);
		return (NULL);
	}
	ft_read(fd, buf, &buffer);
	free(buf);
	if (buffer && buffer[0] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}

char	*ft_get_line(char *buffer)
{
	char	*line;
	int		i;

	if (!buffer)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = (char *)malloc((i + 1) * sizeof(char));
	if (!line)
	{
		free(buffer);
		return (NULL);
	}
	ft_strlcpy(line, buffer, (i + 1));
	return (line);
}

char	*ft_next_line(char **buffer)
{
	int		i;
	char	*rest;

	i = 0;
	while ((*buffer)[i] && (*buffer)[i] != '\n')
		i++;
	if (!(*buffer)[i])
	{
		free(*buffer);
		*buffer = NULL;
		return (NULL);
	}
	rest = (char *)malloc((ft_strlen(*buffer) - i + 1) * sizeof(char));
	if (!rest)
	{
		free(*buffer);
		*buffer = NULL;
		return (NULL);
	}
	i++;
	ft_strlcpy(rest, &((*buffer)[i]), ft_strlen(*buffer) - i + 1);
	free(*buffer);
	*buffer = rest;
	return (*buffer);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = initialize_buffer(buffer);
	if (!buffer)
		return (NULL);
	buffer = ft_read_text(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_get_line(buffer);
	if (!line)
	{
		buffer = NULL;
		return (NULL);
	}
	buffer = ft_next_line(&buffer);
	return (line);
}
/*void leaks(void)
{
	system ("leaks a.out");
}*/

/*int main(void)
{
    int fd;
    char    *next_line;
	atexit(leaks);
    fd = open("pr.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("Error");
        return (1);
    }

    while ((next_line = get_next_line(fd)) != NULL)
    {
        printf("%s\n", next_line);
        free(next_line);
        next_line = NULL;
    }

    close(fd);
    return (0);
}*/