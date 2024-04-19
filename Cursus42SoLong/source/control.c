#include "../includes/so_long.h"

void move_player(t_info_game *game, int position_y, int position_x)
{
    int next_y = game->y + position_y;
    int next_x = game->x + position_x;

    //printf("game: %d\n", game->item);
    if (next_y < 0 || next_y >= game->height || next_x < 0 || next_x >= game->width) 
    {
        printf("Error: Movimiento fuera de los límites del mapa.\n");
        return;
    }

    if (game->map[next_y][next_x] == 'O')
    {
        printf("your lose!\n");
        mlx_destroy_window(game->mlx, game->window);
        exit(EXIT_FAILURE);
    }

    if (game->map[next_y][next_x] == 'E' && game->item == 0)
    {
        printf("Congratulations, you win!\n");
        mlx_destroy_window(game->mlx, game->window);
        exit(EXIT_FAILURE);
    }
    
    else if (game->map[next_y][next_x] == '1' || game->map[next_y][next_x] == 'E') 
    {
        printf("Error: Obstáculo en la siguiente posición.\n");
        return;
    }

    
    if (game->map[next_y][next_x] == 'C') {
        game->item--;
    }

    
    game->map[game->y][game->x] = '0';
    game->map[next_y][next_x] = 'P';
    game->y = next_y;
    game->x = next_x;
    game->moves++;
    printf("%d\n", game->moves);
    add_sprites(game);

    
}


int ft_movement(int key, t_info_game *game)
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

int detect_control(int key, t_info_game *game)
{
    if (key == ESC)
            exit(EXIT_FAILURE);
    ft_movement(key, game);
    return (0);
}