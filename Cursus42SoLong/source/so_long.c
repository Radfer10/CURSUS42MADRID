/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:40:30 by rde-migu          #+#    #+#             */
/*   Updated: 2024/04/11 23:16:48 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/*int main()
{
    t_info_game game;

    if (argc != 2)
            return (0);
    ft_memset (&game, 0, sizeof(t_info_game));
    map_reading(&game, argv);
    check_parseo(&game);
    game.mlx = mlx_init();
    game.window = mlx_new_window(game.mlx, (game.width * 40), (game.height * 40), "solong");
    mlx_loop(game.mlx);
}*/

int main(int argc, char **argv)
{
    t_info_game game;

    if (argc != 2)
        return (0);

    ft_memset(&game, 0, sizeof(t_info_game));
    map_reading(&game, argv);
    if (!map_reading(&game, argv))
    {
        printf("Error al abrir el mapa\n");
        return (1);
    }
    /*place_sprites(&game);
    add_sprites(&game);*/
    int window_width = game.width * 40;
    int window_height = game.height * 40;
    game.mlx = mlx_init(); 
    game.window = mlx_new_window(game.mlx, window_width, window_height, "solong");
    mlx_loop(game.mlx);
}