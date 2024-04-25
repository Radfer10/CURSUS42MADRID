/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 00:08:55 by rde-migu          #+#    #+#             */
/*   Updated: 2024/04/26 00:10:15 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define TITLE_SIZE 64

# define PLAYER "./textures/player.xpm"
# define FLOOR "./textures/floor.xpm"
# define WALL "./textures/wall.xpm"
# define EXIT "./textures/exit.xpm"

# define LEFT 0
# define RIGHT 2
# define UP 13
# define DOWN 1
# define ESC 53

# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct t_item_position
{
	int				y_item;
	int				x_item;
}					t_item_position;

typedef struct t_start
{
	char			*dir;
	int				game_height;
	int				game_width;
	int				y;
	int				x;
	int				fd;
	void			*p_img;
	void			*e_img;
	void			*i_img;
	int				player;
	void			*wall;
	int				exit;
	int				item;
	void			*floor;
	int				height;
	int				width;
	char			**map;
	void			*mlx;
	void			*window;
	int				moves;
	int				player_y;
	int				player_x;
	int				exit_y;
	int				exit_x;
	int				num_item;
	t_item_position	*item_position;
}					t_info_game;

int					map_reading(t_info_game *game, char **argv);
void				place_textures(t_info_game *game);
void				add_textures(t_info_game *game);
void				check_parseo(t_info_game *game);
void				ft_init_values(t_info_game *game);
void				move_player(t_info_game *game, int position_y,
						int position_x);
int					detect_control(int key, t_info_game *game);
void				find_player_and_exit(t_info_game *game);
void				find_item_positions(t_info_game *game);
char				**allocate_map(t_info_game *game);
void				copy_values(t_info_game *game, char **map_copy);
char				**copy_map(t_info_game *game);
void				free_map_copy(char **map_copy, int height);
void				free_map_copy(char **map_copy, int height);
void				flood_fill(t_info_game *game, int y, int x,
						char **map_copy);
int					validate_map(t_info_game *game);
#endif