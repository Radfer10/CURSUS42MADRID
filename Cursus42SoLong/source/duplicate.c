/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 21:09:33 by rde-migu          #+#    #+#             */
/*   Updated: 2024/04/25 23:29:39 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**allocate_map(t_info_game *game)
{
	char	**map_copy;
	int		i;

	map_copy = malloc(game->height * sizeof(*map_copy));
	if (map_copy == NULL)
	{
		ft_printf("Error: No se pudo asignar memoria\n");
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (i < game->height)
	{
		map_copy[i] = malloc(game->width * sizeof(*map_copy[i]));
		if (map_copy[i] == NULL)
		{
			ft_printf("Error: No se pudo asignar memoria\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (map_copy);
}

void	copy_values(t_info_game *game, char **map_copy)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			map_copy[i][j] = game->map[i][j];
			j++;
		}
		i++;
	}
}

char	**copy_map(t_info_game *game)
{
	char	**map_copy;

	map_copy = allocate_map(game);
	copy_values(game, map_copy);
	return (map_copy);
}

void	free_map_copy(char **map_copy, int height)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(map_copy[i]);
		i++;
	}
	free(map_copy);
}
