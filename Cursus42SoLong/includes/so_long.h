#ifndef SO_LONG_H
# define SO_LONG_H

# define TITLE_SIZE 64

# define PLAYER     "./sprites/player.xpm"
# define ENEMY      "./sprites/enemy.xpm"
# define FLOOR      "./sprites/floor.xpm"
# define WALL       "./sprites/wall.xpm"
# define EXIT       "./sprites/exit.xpm"

# define LEFT 0
# define RIGHT 2
# define UP 13
# define DOWN 1
# define ESC 53



# include "../mlx/mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include "get_next_line.h"
# include <string.h>
# include "../libft/libft.h"





typedef struct{
    int y_item;
    int x_item;
} t_item_position;

typedef struct t_start{
    char    *dir;
    int     game_height;
    int     game_width;
    int     y;
    int     x;
    int     fd;
    void   *player_ptr;
    void    *exit_ptr;
    void    *item_ptr;
    int    player; 
    void    *wall;
    int    exit;
    int    item;
    void    *floor;
    void    *enemy;
    int     height;
    int     width;
    char    **map;
    void    *mlx;
    void    *window;
    int     moves;
    void    *enemy_ptr;
    int     player_y;
    int     player_x;
    int     exit_y;
    int     exit_x;
    int     num_item;
    t_item_position *item_position;
} t_info_game;



void	*ft_memset(void *b, int c, size_t len);
int map_reading(t_info_game *game, char **argv);
void place_sprites(t_info_game *game);
void add_sprites(t_info_game *game);
void    check_parseo(t_info_game *game);
void ft_init_values(t_info_game *game);
void    move_player(t_info_game *game, int position_y, int position_x);
int detect_control(int key, t_info_game *game);
void find_player_and_exit(t_info_game *game);
void find_item_positions(t_info_game *game);
int validate_map(t_info_game *game);
void	print_moves_screen(t_info_game *map);
void    choose_player(t_info_game *game, int position_y, int position_x);


#endif



