#include "../includes/so_long.h"

static int  width_of_map(char *str)
{
    int whidthmap;

    whidthmap = 0;
    while (str[whidthmap] != '\0')
                whidthmap++;
    if (str[whidthmap] == '\n')
                whidthmap--;
    return (whidthmap);
}

static int  add_line(t_info_game *game, char *line)
{
    char    **temp;
    int     i;

    if (!line)
        return (0);
    
    temp = malloc((game->height + 1) * sizeof(char *));
    if (!temp)
        return (0);
    
    i = 0;
    while (i < game->height)
    {
        temp[i] = game->map[i];
        i++;
    }
    temp[game->height++] = line;
    free(game->map);
    game->map = temp;
    return (1);
}

int map_reading(t_info_game *game, char **argv)
{
    char    *readmap;
    
    game->fd = open(argv[1], O_RDONLY);
    if (game->fd < 0)
        return (0);
    
    while ((readmap = get_next_line(game->fd)))
    {
        if (!add_line(game, readmap))
        {
            printf("Error al agregar una linea al mapa\n");
            close(game->fd);
            return (0);
        }
        game->height++;
    }
    close(game->fd);
    game->width = width_of_map(game->map[0]);
    return (1);
}