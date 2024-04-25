/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 21:30:50 by rde-migu          #+#    #+#             */
/*   Updated: 2024/04/25 23:08:28 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	print_moves_(t_info_game *map)
{
	char	*str;

	str = ft_itoa(map->moves);
	mlx_string_put(map->mlx, map->window, 10, 27, 0xFFFFFF, "Moves: ");
	mlx_string_put(map->mlx, map->window, 75, 27, 0xFFFFFF, str);
	free(str);
}

int	check_next_position(t_info_game *game, int next_y, int next_x)
{
	if (next_y < 0 || next_y >= game->height || next_x < 0
		|| next_x >= game->width)
	{
		ft_printf("Error: Movimiento fuera de los límites del mapa.\n");
		return (0);
	}
	if (game->map[next_y][next_x] == 'O')
	{
		ft_printf("your lose!\n");
		mlx_destroy_window(game->mlx, game->window);
		exit(EXIT_FAILURE);
	}
	if (game->map[next_y][next_x] == 'E' && game->item == 0)
	{
		ft_printf("Congratulations, you win!\n");
		mlx_destroy_window(game->mlx, game->window);
		exit(EXIT_FAILURE);
	}
	else if (game->map[next_y][next_x] == '1'
		|| game->map[next_y][next_x] == 'E')
	{
		return (0);
	}
	return (1);
}

void	move_player(t_info_game *game, int position_y, int position_x)
{
	int	next_y;
	int	next_x;

	next_y = game->y + position_y;
	next_x = game->x + position_x;
	if (!check_next_position(game, next_y, next_x))
		return ;
	if (game->map[next_y][next_x] == 'C')
	{
		game->item--;
	}
	game->map[game->y][game->x] = '0';
	game->map[next_y][next_x] = 'P';
	game->y = next_y;
	game->x = next_x;
	game->moves++;
	choose_player(game, position_y, position_x);
	ft_printf("%d\n", game->moves);
	add_textures(game);
	print_moves_(game);
}

int	ft_movement(int key, t_info_game *game)
{
	if (key == UP)
		move_player(game, -1, 0);
	if (key == DOWN)
		move_player(game, 1, 0);
	if (key == LEFT)
		move_player(game, 0, -1);
	if (key == RIGHT)
		move_player(game, 0, 1);
	return (0);
}

int	detect_control(int key, t_info_game *game)
{
	if (key == ESC)
		exit(EXIT_FAILURE);
	ft_movement(key, game);
	return (0);
}
