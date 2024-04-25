/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_caracters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 20:09:07 by rde-migu          #+#    #+#             */
/*   Updated: 2024/04/25 21:09:53 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	find_player(t_info_game *game)
{
	int	y;
	int	x;

	game->player_y = -1;
	game->player_x = -1;
	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'P')
			{
				game->player_y = y;
				game->player_x = x;
			}
			x++;
		}
		y++;
	}
	if (game->player_y == -1 || game->player_x == -1)
	{
		ft_printf("Error: no se encontró al jugador\n");
		exit(EXIT_FAILURE);
	}
}

void	find_exit(t_info_game *game)
{
	int	y;
	int	x;

	game->exit_y = -1;
	game->exit_x = -1;
	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'E')
			{
				game->exit_y = y;
				game->exit_x = x;
			}
			x++;
		}
		y++;
	}
	if (game->exit_y == -1 || game->exit_x == -1)
	{
		ft_printf("Error: No se encontró salida\n");
		exit(EXIT_FAILURE);
	}
}

void	find_player_and_exit(t_info_game *game)
{
	find_player(game);
	find_exit(game);
}

void	find_items(t_info_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'C')
			{
				game->item_position[game->num_item].y_item = y;
				game->item_position[game->num_item].x_item = x;
				game->num_item++;
			}
			x++;
		}
		y++;
	}
}

void	find_item_positions(t_info_game *game)
{
	game->item_position = malloc(game->height * game->width
			* sizeof(*game->item_position));
	if (game->item_position == NULL)
	{
		ft_printf("Error: No se pudo asignar memoria para los ítems\n");
		exit(EXIT_FAILURE);
	}
	find_items(game);
}
