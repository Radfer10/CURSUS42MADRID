
/*#include "../includes/so_long.h"

void place_player(t_info_game *game, int heightmap, int widthmap)
{
    mlx_put_image_to_window(game->mlx, game->window, game->player, widthmap * TITLE_SIZE, heightmap * TITLE_SIZE);
    game-> y = heightmap;
    game-> x = widthmap;
}
void place_item(t_info_game *game, int heightmap, int widthmap)
{
    mlx_put_image_to_window(game->mlx, game->window, game->item, widthmap * TITLE_SIZE, heightmap * TITLE_SIZE);
    game->item++;
}

void place_sprites(t_info_game *game)
{
    int i;
    int j;

    game->floor = mlx_xpm_file_to_image(game->mlx, "sprites/floor.xpm", &i, &j);
    game->player = mlx_xpm_file_to_image(game->mlx, "sprites/player.xpm", &i, &j);
    game->item = mlx_xpm_file_to_image(game->mlx, "sprites/item.xpm", &i, &j);
    game->wall = mlx_xpm_file_to_image(game->mlx, "sprite/wall2.xpm", &i, &j);
    game->enemy = mlx_xpm_file_to_image(game->mlx, "sprites/enemy.xpm", &i, &j);
    game->exit = mlx_xpm_file_to_image(game->mlx, "sprites/exit.xpm", &i, &j);
}

void add_sprites(t_info_game *game)
{
    int heightmap;
    int whidthmap;

    heightmap = 0;
    game->item = 0;

    while (heightmap < game->height)
    {
        whidthmap = 0;
        
        while(game->map[heightmap][whidthmap])
        {
            if (game->map[heightmap][whidthmap] == '1')
                mlx_put_image_to_window(game->mlx, game->window, game->wall, whidthmap * TITLE_SIZE, heightmap * TITLE_SIZE);
            if (game->map[heightmap][whidthmap] == 'P')
                place_player(game, heightmap, whidthmap);
            if (game->map[heightmap][whidthmap] == 'I')
                place_item(game, heightmap, whidthmap);
            if (game->map[heightmap][whidthmap] == '0')
                mlx_put_image_to_window(game->mlx, game->window, game->floor, whidthmap * TITLE_SIZE, heightmap * TITLE_SIZE);
            if (game->map[heightmap][whidthmap] == 'E')
                mlx_put_image_to_window(game->mlx, game->window, game->exit, whidthmap * TITLE_SIZE, heightmap * TITLE_SIZE);
        }
        whidthmap++;
    }
    heightmap++;
}*/


