/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_values_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-migu <rde-migu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 21:30:48 by rde-migu          #+#    #+#             */
/*   Updated: 2024/04/25 23:02:11 by rde-migu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	ft_init_values(t_info_game *game)
{
	game->exit = 0;
	game->item = 0;
	game->player = 0;
	game->window = 0;
	game->mlx = 0;
	game->map = 0;
	game->wall = 0;
	game->fd = 0;
	game->floor = 0;
	game->enemy = 0;
	game->width = 0;
	game->height = 0;
	game->i_img = 0;
	game->e_img = 0;
	game->moves = 0;
}
