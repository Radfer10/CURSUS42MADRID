#include "../includes/so_long.h"


static int	horizontalwall(t_info_game *game)
{
	int	i;
	int	j;

	i = game->width;
	j = 0;
	while (j < i)
	{
		if (game->map[0][i] != '1' && game->map[game->height - 1][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

static int	verticalwall(t_info_game *game)
{
	int	heightmap;
	int	widthmap;

	heightmap = 0;
	widthmap = game->width;
	while (heightmap < game->height)
	{
		if (!(game->map[heightmap][0] == '1' && game->map[heightmap][widthmap - 1] == '1'))
			return (0);
		heightmap++;
	}
	return (1);
}

static void	if_walls(t_info_game *game)
{
	int	verticalwalls;
	int	horizontalwalls;

	verticalwalls = verticalwall(game);
	horizontalwalls = horizontalwall(game);
	if (!verticalwalls || !horizontalwalls)
	{
		printf("\nThis map is missing the walls\n");
		exit(EXIT_FAILURE);
	}
}

static void	count_checker(t_info_game *game, int heightmap, int widthmap)
{
	if (game->map[heightmap][widthmap] != '1' &&
			game->map[heightmap][widthmap] != '0' &&
			game->map[heightmap][widthmap] != 'P' &&
			game->map[heightmap][widthmap] != 'E' &&
			game->map[heightmap][widthmap] != 'C' &&
			game->map[heightmap][widthmap] != 'O' &&
			game->map[heightmap][widthmap] != '\n' &&
			game->map[heightmap][widthmap] != '\0')
	{
		printf("\nError Here!%c\n", game->map[heightmap][widthmap]);
        exit(EXIT_FAILURE);
	}
	if (game->map[heightmap][widthmap] == 'C')
			game->item++;
	if (game->map[heightmap][widthmap] == 'P')
			game->player++;
	if (game->map[heightmap][widthmap] == 'E')
			game->exit++;
}

void	character_valid(t_info_game *game)
{
	int	heightmap;
	int	widthmap;

	heightmap = 0;
	while (heightmap < game->height)
	{
		widthmap = 0;
		while (widthmap <= game->width)
		{
			
			count_checker(game, heightmap, widthmap);
            
			widthmap++;
		}
		heightmap++;
        
	}
	if (game->player != 1 || game->exit != 1 || !(game->item >= 1))
	{
		printf("player: %d, exit; %d, item: %d", game->player, game->exit, game->item);
		printf("\nError\nSomething is wrong!\n");
		printf("either player, exit or collectable issue\n");
		exit(EXIT_FAILURE);
	}
	
}


void	check_parseo(t_info_game *game)
{
	if_walls(game);
	character_valid(game);
}


/*int check_border_walls(t_info_game *game) {
    int i = 0;
    while (i < game->width) {
        if (game->map[0][i] != '1' || game->map[game->height - 1][i] != '1') {
            printf("Top or bottom wall missing at position (%d, %d)\n", 0, i);
            return 0;
        }
        i++;
    }
    
    int j = 0;
    while (j < game->height) {
        if (game->map[j][0] != '1' || game->map[j][game->width - 1] != '1') {
            printf("Left or right wall missing at position (%d, %d)\n", j, 0);
            return 0;
        }
        j++;
    }
    
    
    if (game->map[game->height - 1][game->width - 1] != '1') {
        printf("Bottom right wall missing\n");
        return 0;
    }

    printf("Border walls are present\n");
    return 1;
}

int check_essential_elements(t_info_game *game) {
    

    int i = 0;
    while (i < game->height) {
        int j = 0;
        while (j < game->width) {
            if (game->map[i][j] == 'P') {
                game->player++;
            } else if (game->map[i][j] == 'E') {
                game->exit++;
            } else if (game->map[i][j] == 'C') {
                game->item++;
            }
            j++;
        }
        i++;
    }
    return (game->player == 1 && game->exit >= 1 && game->item >= 1);
}



int check_map_format(t_info_game *game) {
    int i = 0;
    while (i < game->height) {
        int j = 0;
        while (j < game->width) {
            char cell = game->map[i][j];
            if (cell != '0' && cell != '1' && cell != 'P' && cell != 'E' && cell != 'C') {
                return 0;
            }
            j++;
        }
        i++;
    }
    return 1;
}

int check_parseo(t_info_game *game) {
    if (!check_border_walls(game)) {
        printf("Map is missing walls around the border\n");
        return 0;
    }
    if (!check_essential_elements(game)) {
        printf("Map is missing essential elements\n");
        return 0;
    }
    
    
    if (!check_map_format(game)) {
        printf("Map has invalid characters or uneven rows\n");
        return 0;
    }
    return 1;
}*/
