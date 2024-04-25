/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 00:32:10 by rde-migu          #+#    #+#             */
/*   Updated: 2024/04/25 22:59:03 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	validate_limits(t_info_game *game, int y, int x, char **map_copy)
{
	int	dy[4];
	int	dx[4];
	int	i;
	int	new_y;
	int	new_x;

	dy[0] = 1;
	dy[1] = -1;
	dy[2] = 0;
	dy[3] = 0;
	dx[0] = 0;
	dx[1] = 0;
	dx[2] = 1;
	dx[3] = -1;
	i = 0;
	while (i < 4)
	{
		new_y = y + dy[i];
		new_x = x + dx[i];
		if (new_y >= 0 && new_y < game->height && new_x >= 0
			&& new_x < game->width)
			flood_fill(game, new_y, new_x, map_copy);
		i++;
	}
}

void	flood_fill(t_info_game *game, int y, int x, char **map_copy)
{
	if (y < 0 || y >= game->height || x < 0 || x >= game->width)
	{
		return ;
	}
	if (map_copy[y][x] == 'V')
	{
		return ;
	}
	if (map_copy[y][x] != '1')
	{
		map_copy[y][x] = 'V';
	}
	else
	{
		return ;
	}
	validate_limits(game, y, x, map_copy);
}

int	check_cells(t_info_game *game, char **map_copy)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] != '1' && map_copy[y][x] != 'V')
			{
				ft_printf("Error:\nCasilla (%d, %d) inaccesible\n", y, x);
				free_map_copy(map_copy, game->height);
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	check_exit_item(t_info_game *game)
{
	if ((game->map[game->exit_y][game->exit_x] != 'V'
		&& game->map[game->exit_y][game->exit_x] == '1'))
	{
		ft_printf("Error: Salida o item inaccesible en el mapa\n");
		return (0);
	}
	return (1);
}

int	validate_map(t_info_game *game)
{
	char	**map_copy;
	int		accessible_item;

	map_copy = copy_map(game);
	flood_fill(game, game->player_y, game->player_x, map_copy);
	accessible_item = 0;
	if (!check_cells(game, map_copy))
		return (0);
	free_map_copy(map_copy, game->height);
	if (!check_exit_item(game))
		return (0);
	return (1);
}
