
#include "../includes/so_long.h"

void ft_init_values(t_info_game *game)
{
    game->exit = 0;
    game->item = 0;
    game->player = 0;
    game->window = 0;
    game->mlx = 0;
    game->map = 0;
    game->wall = 0;
    game->fd =  0;
    game->floor = 0; 
    game->enemy = 0; 
    game->width = 0; 
    game->height = 0;
    game->item_ptr = 0;
    game->exit_ptr = 0; 
    game->moves = 0;
}
  