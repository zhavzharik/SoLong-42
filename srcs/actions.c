/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 17:28:09 by abridger          #+#    #+#             */
/*   Updated: 2021/10/21 14:49:41 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_up(int key, t_data **game)
{
	int	x;
	int	y;

	x = (*game)->x_pos_player;
	y = (*game)->y_pos_player;
	if (key == XK_W)
	{
		if (whether_can_move(game, x, y - 1))
		{
			(*game)->y_pos_player -= 1;
			check_game_score(game, x, y - 1);
			change_map(game, '0', x, y);
			change_map(game, 'P', (*game)->x_pos_player, (*game)->y_pos_player);
		}
		draw_map(game);
	}
}

void	move_down(int key, t_data **game)
{
	int	x;
	int	y;

	x = (*game)->x_pos_player;
	y = (*game)->y_pos_player;
	if (key == XK_S)
	{
		if (whether_can_move(game, x, y + 1))
		{
			(*game)->y_pos_player += 1;
			check_game_score(game, x, y + 1);
			change_map(game, '0', x, y);
			change_map(game, 'P', (*game)->x_pos_player, (*game)->y_pos_player);
		}
		draw_map(game);
	}
}

void	move_left(int key, t_data **game)
{
	int	x;
	int	y;

	x = (*game)->x_pos_player;
	y = (*game)->y_pos_player;
	if (key == XK_A)
	{
		if (whether_can_move(game, x - 1, y))
		{
			(*game)->x_pos_player -= 1;
			(*game)->flag_player = 0;
			check_game_score(game, x - 1, y);
			change_map(game, '0', x, y);
			change_map(game, 'P', (*game)->x_pos_player, (*game)->y_pos_player);
		}
		draw_map(game);
	}
}

void	move_right(int key, t_data **game)
{
	int	x;
	int	y;

	x = (*game)->x_pos_player;
	y = (*game)->y_pos_player;
	if (key == XK_D)
	{
		if (whether_can_move(game, x + 1, y))
		{
			(*game)->x_pos_player += 1;
			(*game)->flag_player = 1;
			check_game_score(game, x + 1, y);
			change_map(game, '0', x, y);
			change_map(game, 'P', (*game)->x_pos_player, (*game)->y_pos_player);
		}
		draw_map(game);
	}
}
