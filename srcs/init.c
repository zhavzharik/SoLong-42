/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:42:30 by abridger          #+#    #+#             */
/*   Updated: 2021/10/18 15:09:15 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_data	*init_game(t_data *game)
{
	game->map_h = 0;
	game->map_l = 0;
	game->wall = NULL;
	game->player = NULL;
	game->cake = NULL;
	game->space = NULL;
	game->exit = NULL;
	game->x_pos_player = 0;
	game->y_pos_player = 0;
	return (game);
}

t_visual	*init_window(t_visual *window, t_data *game)
{
	window->mlx_ptr = mlx_init();
	window->win_ptr = mlx_new_window(window->mlx_ptr, game->map_l * PIC_SIDE,
			game->map_h * PIC_SIDE, "So Long!");
	return (window);
}
