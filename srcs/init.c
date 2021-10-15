/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:42:30 by abridger          #+#    #+#             */
/*   Updated: 2021/10/15 22:40:02 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_data	*init_game(t_data *game)
{
	game->map_h = 0;
	game->map_l = 0;
	game->x_pos_player = 0;
	game->y_pos_player = 0;
	return (game);
}
