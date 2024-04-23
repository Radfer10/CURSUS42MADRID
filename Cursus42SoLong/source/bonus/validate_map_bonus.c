#include "../../includes/so_long_bonus.h"

void find_player_and_exit(t_info_game *game) {
    game->player_y = -1;
    game->player_x = -1;
    game->exit_y = -1;
    game->exit_x = -1;

    int y = 0;
    while (y < game->height) {
        int x = 0;
        while (x < game->width) {
            if (game->map[y][x] == 'P') {
                game->player_y = y;
                game->player_x = x;
            } else if (game->map[y][x] == 'E') {
                game->exit_y = y;
                game->exit_x = x;
            }
            x++;
        }
        y++;
    }

    if (game->player_y == -1 || game->player_x == -1) {
        ft_printf("Error: no se encontró al jugador en el mapa\n");
        exit(EXIT_FAILURE);
    }

    if (game->exit_y == -1 || game->exit_x == -1) {
        ft_printf("Error: No se encontró salida en el mapa\n");
        exit(EXIT_FAILURE);
    }
}

void find_item_positions(t_info_game *game) {
    game->item_position = malloc(game->height * game->width * sizeof(*game->item_position));
    if (game->item_position == NULL) {
        ft_printf("Error: No se pudo asignar memoria para las posiciones de los ítems\n");
        exit(EXIT_FAILURE);
    }

    int y = 0;
    while (y < game->height) {
        int x = 0;
        while (x < game->width) {
            if (game->map[y][x] == 'C') {
                game->item_position[game->num_item].y_item = y;
                game->item_position[game->num_item].x_item = x;
                game->num_item++;
            }
            x++;
        }
        y++;
    }
}

char **copy_map(t_info_game *game) {
    char **map_copy = malloc(game->height * sizeof(*map_copy));
    if (map_copy == NULL) {
        ft_printf("Error: No se pudo asignar memoria para la copia del mapa\n");
        exit(EXIT_FAILURE);
    }

    int i = 0;
    while (i < game->height) {
        map_copy[i] = malloc(game->width * sizeof(*map_copy[i]));
        if (map_copy[i] == NULL) {
            ft_printf("Error: No se pudo asignar memoria para la copia del mapa\n");
            exit(EXIT_FAILURE);
        }
        int j = 0;
        while (j < game->width) {
            map_copy[i][j] = game->map[i][j];
            j++;
        }
        i++;
    }
    return map_copy;
}

void free_map_copy(char **map_copy, int height) {
    int i = 0;
    while (i < height) {
        free(map_copy[i]);
        i++;
    }
    free(map_copy);
}

void flood_fill(t_info_game *game, int y, int x, char **map_copy) {
    if (y < 0 || y >= game->height || x < 0 || x >= game->width) {
        return;
    }

    if (map_copy[y][x] == 'V') {
        return;
    }

    if (map_copy[y][x] != '1') {
        map_copy[y][x] = 'V'; 
        //printf("Casilla (%d, %d) marcada como visitada.\n", y, x);
    } else {
        return; 
    }

    int dy[] = {1, -1, 0, 0};
    int dx[] = {0, 0, 1, -1};

    int i = 0;
    while (i < 4) {
        int new_y = y + dy[i];
        int new_x = x + dx[i];
        if (new_y >= 0 && new_y < game->height && new_x >= 0 && new_x < game->width) {
            flood_fill(game, new_y, new_x, map_copy);
        }
        i++;
    }
}

int validate_map(t_info_game *game) {
    char **map_copy = copy_map(game);

    flood_fill(game, game->player_y, game->player_x, map_copy);

    int accessible_item = 0;

    int y = 0;
    while (y < game->height) {
        int x = 0;
        while (x < game->width) {
            if (game->map[y][x] != '1' && map_copy[y][x] != 'V') {
                ft_printf("Error: Casilla (%d, %d) inaccesible en el mapa\n", y, x);
                free_map_copy(map_copy, game->height);
                return 0;
            }
            x++;
        }
        y++;
    }

    free_map_copy(map_copy, game->height);

    
    if ((game->map[game->exit_y][game->exit_x] != 'V' && game->map[game->exit_y][game->exit_x] == '1') && !accessible_item) {
        ft_printf("Error: Salida o item inaccesible en el mapa\n");
        return 0;
    }

    return 1;
}





