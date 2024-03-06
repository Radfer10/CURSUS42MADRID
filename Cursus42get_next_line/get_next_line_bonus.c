/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:42:27 by rde-migu          #+#    #+#             */
/*   Updated: 2024/03/06 11:32:13 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_next_line(char *buffer)
{
	int	i;
	int	j;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	i++;
	if (!buffer[i])
	{
		free(buffer);
		return (0);
	}
	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (buffer[i])
	line[j++] = buffer[i++];
	free(buffer);
	return (&*line);
}
char	*ft_get_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
	return (0);
	while (buffer[i] && buffer[i] != '\n')
	i++;
	line = ft_calloc(i + 2, sizeof (char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
	line[i++] = '\n';
	return (&*line);
}
char	*ft_read_file(int fd, char *str)
{
	char	*buffer;
	int		readbyte;
	
	if (!str)
		str = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof (char));
	readbyte = 1;
	while (readbyte > 0)
	{
		readbyte = read(fd, buffer, BUFFER_SIZE);
		if (readbyte == -1)
		{
			free(buffer);
			return (0);
		}
		buffer[readbyte] = 0;
		char	*temp;
		temp = str;
		str = ft_strjoin(temp, buffer);
		free(temp);
		if (ft_strchr(buffer, '\n'))
		{
			free(buffer);
			return (str);
		}

	}
	free(buffer);
	return &(*str);
}

char	*get_next_line (int fd)
{
	char	*line;
	static char	*buffer[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	return (NULL);
	buffer = ft_read_file(fd, buffer);
	if (!buffer)
	return (NULL);
	line = ft_get_line(buffer);
	buffer = ft_next_line(buffer);
	return (line);
}
/*int main()
{
	int fd1 = open("ejemplo.txt", O_RDONLY);
	int	fd2 = open("ejemplo2.txt", O_RDONLY);
	ft_add_fd(fd1);
	ft_add_fd(fd2);

	char	*line;
	while ((line = get_next_line(fd1)) != NULL)
	{
		printf("%s\n", line);
		free(line);
	}
	while ((line = get_next_line(fd2)) != NULL)
	{
		printf("%s\n", line);
		free(line);
	}
	ft_free_fd();
	return (0);
}*/