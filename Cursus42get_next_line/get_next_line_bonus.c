/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:42:27 by rde-migu          #+#    #+#             */
/*   Updated: 2024/03/04 17:48:02 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static t_fd_buffer *fd_list;

void ft_add_fd(int fd)
{
    t_fd_buffer *new_fd = (t_fd_buffer *)malloc(sizeof(t_fd_buffer));
    if (!new_fd)
        return;
    new_fd->fd = fd;
    new_fd->buffer = NULL;
    new_fd->next = NULL;

    if (!fd_list)
    {
        fd_list = new_fd;
    }
    else
    {
        t_fd_buffer *current = fd_list;
        while (current->next)
            current = current->next;
        current->next = new_fd;
    }
}

void ft_free_fd()
{
    t_fd_buffer *current = fd_list;
    while (current)
    {
        t_fd_buffer *temp = current;
        current = current->next;
        free(temp->buffer);
        free(temp);
    }
    fd_list = NULL;
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