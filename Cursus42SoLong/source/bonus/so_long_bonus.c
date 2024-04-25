/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:40:30 by rde-migu          #+#    #+#             */
/*   Updated: 2024/04/25 22:44:44 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

int	check_errors(int argc, char **argv, t_info_game *game)
{
	if (argc != 2)
	{
		ft_printf("Uso: %s <mapa>\n", argv[0]);
		return (1);
	}
	if (!map_reading(game, argv))
	{
		ft_printf("Error al abrir el mapa\n");
		return (1);
	}
	find_player_and_exit(game);
	find_item_positions(game);
	if (!validate_map(game))
	{
		ft_printf("Error:\n el mapa no es válido\n");
		return (1);
	}
	check_parseo(game);
	return (0);
}

void	start_game(t_info_game *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, (game->width * TITLE_SIZE),
			(game->height * TITLE_SIZE), "solong_BONUS");
	place_textures(game);
	add_textures(game);
	mlx_key_hook(game->window, detect_control, game);
	mlx_hook(game->window, 17, 0, (void *)exit, 0);
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	t_info_game	game;

	ft_init_values(&game);
	if (check_errors(argc, argv, &game) != 0)
		return (1);
	start_game(&game);
	return (0);
}
