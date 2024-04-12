
/*#include "../includes/ft_printf.h"
#include "../includes/so_long.h"

void move_player(t_info_game *map, int new_position, char condition)
{
    if (map->mapall[new_position] == condition && map->max_score == map->score)
    {
        map->gameover++;
        map->step++;
        ft_printf("Moves: %i\n", map->step);
    }
    if (map->mapall[new_position] != '1' &&map->mapall[new_position] != condition)
    {
        if (map->mapall[new_position] == 'C')
            map->score++;
        map->mapall[new_position] = 'P';
        map->step++;
        ft_printf("Moves: %i\n", map->step);
    }
}

void    ft_wkey(t_info_game *map)
{
    int player_position = 0;
    while (map->mapall[player_position] != 'P')
        player_position++;
    move_player(map, player_position - map->width, 'E');
}

void    ft_skey(t_info_game *map)
{
    int player_position = 0;
    while (map->mapall[player_position] != 'P')
        player_position++;
    move_player(map, player_position + map->width, 'E');
}

void    ft_akey(t_info_game *map)
{
    int player_position = 0;
    while (map->mapall[player_position] != 'P')
        player_position++;
    move_player(map, player_position + 1, 'E');
}

void    ft_wkey(t_info_game *map)
{
    int player_position = 0;
    while (map->mapall[player_position] != 'P')
        player_position++;
    move_player(map, player_position - 1, 'E');
}*/

