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
		ft_printf("\nThis map is missing the walls\n");
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
		ft_printf("\nError Here!%c\n", game->map[heightmap][widthmap]);
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
		ft_printf("player: %d, exit; %d, item: %d", game->player, game->exit, game->item);
		ft_printf("\nError\nSomething is wrong!\n");
		ft_printf("either player, exit or collectable issue\n");
		exit(EXIT_FAILURE);
	}
	
}


void	check_parseo(t_info_game *game)
{
	if_walls(game);
	character_valid(game);
}


