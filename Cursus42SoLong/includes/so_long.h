#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef TITLE_SIZE
# define TITLE_SIZE 64
# endif

# define PLAYER     "./sprites/player.xpm"
# define ENEMY      "./sprites/enemy.xpm"
# define FLOOR      "./sprites/floor.xpm"
# define WALL       "./sprites/wall.xpm"
# define EXIT       "./sprites/exit.xpm"


# include "../mlx/mlx.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include "get_next_line.h"


#endif



typedef struct {
    int     y;
    int     x;
    int     fd;
    void    *player; 
    void    *wall;
    void    *exit;
    void    *item;
    void    *floor;
    void    *enemy;
    int     height;
    int     width;
    char    **map;
    void    *mlx;
    void    *window;
} t_info_game;

int main();
void	*ft_memset(void *b, int c, size_t len);
int map_reading(t_info_game *game, char **argv);
/*void place_sprites(t_info_game *game);
void add_sprites(t_info_game *game);*/


