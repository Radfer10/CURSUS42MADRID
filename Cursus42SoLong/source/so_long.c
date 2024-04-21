/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:40:30 by rde-migu          #+#    #+#             */
/*   Updated: 2024/04/21 02:56:59 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int main(int argc, char **argv) {
    
    t_info_game game;
    ft_init_values(&game);

    if (argc != 2) {
        printf("Uso: %s <mapa>\n", argv[0]);
        return 1;
    }
    if (!map_reading(&game, argv)) {
        printf("Error al abrir el mapa\n");
        return 1;
    }
    find_player_and_exit(&game);
    find_item_positions(&game);
    if (!validate_map(&game)) {
        printf("Error: el mapa no es válido\n");
        return 1;
    }
    check_parseo(&game);
    game.mlx = mlx_init();
    game.window = mlx_new_window(game.mlx, (game.width * TITLE_SIZE), (game.height * TITLE_SIZE), "solong");
    place_sprites(&game);
    add_sprites(&game);
    mlx_key_hook(game.window, detect_control, &game);
    mlx_hook(game.window, 17, 0, (void *)exit, 0);
    mlx_loop(game.mlx);
    return (0);
}