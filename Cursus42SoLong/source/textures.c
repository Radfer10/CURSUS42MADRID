/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 23:57:15 by rde-migu          #+#    #+#             */
/*   Updated: 2024/04/26 00:05:54 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	place_player(t_info_game *game, int heightmap, int widthmap)
{
	mlx_put_image_to_window(game->mlx, game->window, game->p_img, widthmap
		* TITLE_SIZE, heightmap * TITLE_SIZE);
	game->y = heightmap;
	game->x = widthmap;
}

void	place_textures(t_info_game *game)
{
	int	i;
	int	j;

	game->floor = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm", &i,
			&j);
	if (game->floor == NULL)
		return (perror("Error\n"), exit(2));
	game->p_img = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm", &i,
			&j);
	if (game->p_img == NULL)
		return (perror("Error\n"), exit(2));
	game->i_img = mlx_xpm_file_to_image(game->mlx, "textures/item.xpm", &i, &j);
	if (game->i_img == NULL)
		return (perror("Error\n"), exit(2));
	game->wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &i, &j);
	if (game->wall == NULL)
		return (perror("Error\n"), exit(2));
	game->e_img = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm", &i, &j);
	if (game->e_img == NULL)
		return (perror("Error\n"), exit(2));
}

void	draw_textures(t_info_game *game, int heightmap, int widthmap)
{
	mlx_put_image_to_window(game->mlx, game->window, game->floor, widthmap
		* TITLE_SIZE, heightmap * TITLE_SIZE);
	if (game->map[heightmap][widthmap] == '1' && game->wall != NULL)
	{
		mlx_put_image_to_window(game->mlx, game->window, game->wall, widthmap
			* TITLE_SIZE, heightmap * TITLE_SIZE);
	}
	else if (game->map[heightmap][widthmap] == 'P')
	{
		place_player(game, heightmap, widthmap);
	}
	else if (game->map[heightmap][widthmap] == 'C' && game->i_img != NULL)
	{
		mlx_put_image_to_window(game->mlx, game->window, game->i_img, widthmap
			* TITLE_SIZE, heightmap * TITLE_SIZE);
	}
	else if (game->map[heightmap][widthmap] == 'E' && game->e_img != NULL)
	{
		mlx_put_image_to_window(game->mlx, game->window, game->e_img, widthmap
			* TITLE_SIZE, heightmap * TITLE_SIZE);
	}
}

void	add_textures(t_info_game *game)
{
	int	heightmap;
	int	widthmap;

	if (game == NULL || game->mlx == NULL || game->window == NULL)
	{
		return ;
	}
	heightmap = 0;
	while (heightmap < game->height)
	{
		widthmap = 0;
		while (widthmap < game->width)
		{
			draw_textures(game, heightmap, widthmap);
			widthmap++;
		}
		heightmap++;
	}
}
