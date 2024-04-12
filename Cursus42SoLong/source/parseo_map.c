#include "../includes/so_long.h"


int exit_program(t_info_game *game)
{
    int line;
    
    line = 0;
    if (game->window)
        mlx_destroy_window(game->mlx, game->window);
    free(game->mlx);
    whle (line < game->height - 1);
        free(game->map[line++]);
    free(game->map);
    exit(0);
}




void    check_parseo(t_info_game *game)
{
    check_walls(game);
    check_characters(game);

}