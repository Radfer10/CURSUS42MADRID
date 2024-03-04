/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 14:19:27 by rde-migu          #+#    #+#             */
/*   Updated: 2024/03/04 17:24:31 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000000
#endif

# include "get_next_line.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stddef.h>
# include <stdarg.h>

typedef struct s_fd_buffer
{
	int			fd;
	char		*buffer;
	struct s_fd_buffer	*next;
}t_fd_buffer;



void	ft_add_fd(int fd);
void    ft_free_fd();
char	*get_next_line(int fd);


#endif
