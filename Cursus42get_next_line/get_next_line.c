/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:03:26 by rde-migu          #+#    #+#             */
/*   Updated: 2024/03/21 23:04:47 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*initialize_buffer(char *buffer)
{
	if (!buffer)
	{
		buffer = (char *)malloc(sizeof(char));
		if (!buffer)
			return (NULL);
		buffer[0] = '\0';
	}
	return (buffer);
}

char	*ft_read_text(int fd, char **buffer)
{
	char	buf[BUFFER_SIZE + 1];
	int		readbyte;
	char	*temp;

	readbyte = 1;
	while (readbyte > 0)
	{
		readbyte = read(fd, buf, BUFFER_SIZE);
		if (readbyte == -1 || readbyte == 0)
			break ;
		buf[readbyte] = '\0';
		temp = ft_strjoin(*buffer, buf);
		free(*buffer);
		*buffer = temp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (!*buffer || **buffer == '\0')
	{
		free(*buffer);
		return (NULL);
	}
	return (*buffer);
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

char	*ft_next_line(char *buffer)
{
	int		j;
	int		i;
	char	*rest;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		return (free(buffer), buffer = NULL, NULL);
	}
	rest = (char *)malloc((ft_strlen(buffer) - i + 1) * sizeof(char));
	if (!rest)
	{
		free(buffer);
		return (NULL);
	}
	i++;
	j = 0;
	while (buffer[i])
		rest[j++] = buffer[i++];
	rest[j] = '\0';
	free(buffer);
	return (rest);
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
	buffer = ft_read_text(fd, &buffer);
	if (!buffer)
		return (NULL);
	line = ft_get_line(buffer);
	if (!line)
	{
		buffer = NULL;
		return (NULL);
	}
	buffer = ft_next_line(buffer);
	return (line);
}

/*int	main(void)
{
	int	i;
	int fd;
	char *next_line;
	
	i = 15;
	fd = open("1char.txt", O_RDONLY);

	if (fd == -1)
	{
		printf("Error");
		return (1);
	}
	while (i--)
	{
		next_line = get_next_line(fd);
		printf("%s\n", next_line);
		free(next_line);
		next_line = NULL;
	}
	return (0);
}*/
