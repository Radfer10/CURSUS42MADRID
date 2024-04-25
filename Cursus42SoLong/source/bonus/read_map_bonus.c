/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 21:30:40 by rde-migu          #+#    #+#             */
/*   Updated: 2024/04/24 23:52:14 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

static int	width_of_map(char *str)
{
	int	widthmap;

	widthmap = 0;
	while (str[widthmap] != '\0')
		widthmap++;
	if (str[widthmap - 1] == '\n')
		widthmap--;
	return (widthmap);
}

static char	**resize_map(t_info_game *game, char *line)
{
	char	**temp;
	int		i;

	temp = malloc(game->height * sizeof(char *));
	if (!temp)
		return (NULL);
	i = 0;
	while (i < game->height - 1)
	{
		temp[i] = game->map[i];
		i++;
	}
	temp[game->height - 1] = ft_strdup(line);
	if (!temp[game->height - 1])
	{
		i = 0;
		while (i < game->height - 1)
		{
			free(temp[i]);
			i++;
		}
		free(temp);
		return (NULL);
	}
	return (temp);
}

static int	add_line(t_info_game *game, char *line)
{
	int		length;
	char	**new_map;

	if (!line)
		return (0);
	length = ft_strlen(line);
	if (length > 0 && line[length - 1] == '\n')
		line[length - 1] = '\0';
	game->height++;
	new_map = resize_map(game, line);
	if (!new_map)
	{
		game->height--;
		return (0);
	}
	free(game->map);
	game->map = new_map;
	game->width = width_of_map(game->map[0]);
	return (1);
}

int	map_reading(t_info_game *game, char **argv)
{
	char	*readmap;

	game->fd = open(argv[1], O_RDONLY);
	if (game->fd < 0)
		return (0);
	readmap = get_next_line(game->fd);
	while (readmap)
	{
		add_line(game, readmap);
		if (game->map == NULL)
		{
			ft_printf("Error al agregar una línea al mapa\n");
			close(game->fd);
			return (0);
		}
		readmap = get_next_line(game->fd);
	}
	close(game->fd);
	return (1);
}
