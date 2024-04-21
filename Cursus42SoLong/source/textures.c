
#include "../includes/so_long.h"

void place_player(t_info_game *game, int heightmap, int widthmap)
{
    mlx_put_image_to_window(game->mlx, game->window, game->player_ptr, widthmap * TITLE_SIZE, heightmap * TITLE_SIZE);
    game->y = heightmap;
    game->x = widthmap;
}

void place_sprites(t_info_game *game)
{
    int i;
    int j;

    game->floor = mlx_xpm_file_to_image(game->mlx, "sprites/floor.xpm", &i, &j);
    if (game->floor == NULL)
        return (perror("Error: file couldn't be open"), exit(2));
    /*printf("floor\n width:%d, height:%d", i, j);*/
    game->player_ptr = mlx_xpm_file_to_image(game->mlx, "sprites/player.xpm", &i, &j);
    if (game->player_ptr == NULL)
        return (perror("Error: file couldn't be open"), exit(2));
    /*printf("player\n width:%d, height:%d", i, j);*/
    game->item_ptr = mlx_xpm_file_to_image(game->mlx, "sprites/item.xpm", &i, &j);
    if (game->item_ptr == NULL)
        return (perror("Error: file couldn't be open"), exit(2));
    /*printf("item\n width:%d, height:%d", i, j);*/
    game->wall = mlx_xpm_file_to_image(game->mlx, "sprites/wall.xpm", &i, &j);
        if (game->wall == NULL)
        return (perror("Error: file couldn't be open"), exit(2));
    /*printf("wall\n width:%d, height:%d", i, j);*/
    game->enemy_ptr = mlx_xpm_file_to_image(game->mlx, "sprites/enemy.xpm", &i, &j);
    /*printf("enemy\n width:%d, height:%d", i, j);*/
        if (game->enemy_ptr == NULL)
        return (perror("Error: file couldn't be open"), exit(2));
    game->exit_ptr = mlx_xpm_file_to_image(game->mlx, "sprites/exit.xpm", &i, &j);
        if (game->exit_ptr == NULL)
        return (perror("Error: file couldn't be open"), exit(2));
    /*printf("exit\n width:%d, height:%d", i, j);
    printf("(game->floor: %p, game->window: %p, game->wall: %p).\n", (void*)game->floor, (void*)game->window, (void*)game->wall);*/
}

void add_sprites(t_info_game *game)
{
    if (game == NULL || game->mlx == NULL || game->window == NULL) {
        return;
    }

    int heightmap = 0;
    int widthmap;

    while (heightmap < game->height) {
        widthmap = 0;

        while (widthmap < game->width) {
            mlx_put_image_to_window(game->mlx, game->window, game->floor, widthmap * TITLE_SIZE, heightmap * TITLE_SIZE);

            if (game->map[heightmap][widthmap] == '1' && game->wall != NULL) 
            {
                mlx_put_image_to_window(game->mlx, game->window, game->wall, widthmap * TITLE_SIZE, heightmap * TITLE_SIZE);
            } else if (game->map[heightmap][widthmap] == 'P') 
            {
                place_player(game, heightmap, widthmap);
            } else if (game->map[heightmap][widthmap] == 'C' && game->item_ptr != NULL) 
            {
                mlx_put_image_to_window(game->mlx, game->window, game->item_ptr, widthmap * TITLE_SIZE, heightmap * TITLE_SIZE);
            } else if (game->map[heightmap][widthmap] == 'E' && game->exit_ptr != NULL) 
            {
                mlx_put_image_to_window(game->mlx, game->window, game->exit_ptr, widthmap * TITLE_SIZE, heightmap * TITLE_SIZE);
            } else if (game->map[heightmap][widthmap] == 'O' && game->enemy_ptr != NULL)
                mlx_put_image_to_window(game->mlx, game->window, game->enemy_ptr, widthmap * TITLE_SIZE, heightmap * TITLE_SIZE);
            //printf ("%c", game->map[heightmap][widthmap]);
            widthmap++;
        }
        
        heightmap++;
    }
}
void    choose_player(t_info_game *game, int position_y, int position_x)
{
	if (position_y == 1)
		game->dir = "./sprites/Player.xpm";
	if (position_y == -1)
		game->dir = "./sprites/Player_Up.xpm";
	if (position_x == 1)
		game->dir = "./sprites/Player_Right.xpm";
	if (position_x == -1)
		game->dir = "./sprites/Player_Left.xpm";
	game->player_ptr = mlx_xpm_file_to_image(game->mlx, game->dir,
			&game->game_width, &game->game_height);
	if (game->player_ptr == NULL)
		return (perror("Error: file couldn't be open"), exit(2));
}


