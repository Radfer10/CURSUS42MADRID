/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:42:27 by rde-migu          #+#    #+#             */
/*   Updated: 2024/03/21 21:09:01 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
		free(buffer);
		return (NULL);
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
	static char	*buffer[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (NULL);
	}
	buffer[fd] = initialize_buffer(buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	buffer[fd] = ft_read_text(fd, &buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = ft_get_line(buffer[fd]);
	if (!line)
	{
		buffer[fd] = NULL;
		return (NULL);
	}
	buffer[fd] = ft_next_line(buffer[fd]);
	return (line);
}

/*int main(void) {
	int fd1, fd2;
	char *next_line;

	fd1 = open("el_quijote.txt", O_RDONLY);
	if (fd1 == -1) {
		printf("Error al abrir el archivo el_quijote.txt\n");
		return (1);
	}

	fd2 = open("ejemplo.txt", O_RDONLY);
	if (fd2 == -1) {
		printf("Error al abrir el archivo ejemplo.txt\n");
		close(fd1);
		return (1);
	}

	// Leer y mostrar líneas de el_quijote.txt
	while ((next_line = get_next_line(fd1)) != NULL) {
		printf("%s\n", next_line);
		free(next_line);
	}

	// Leer y mostrar líneas de ejemplo.txt
	while ((next_line = get_next_line(fd2)) != NULL) {
		printf("%s", next_line);
		free(next_line);
	}

	close(fd1);
	close(fd2);

	return (0);
}*/