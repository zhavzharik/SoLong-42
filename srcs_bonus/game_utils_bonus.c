/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:17:08 by abridger          #+#    #+#             */
/*   Updated: 2021/10/27 16:10:01 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	count_present(t_data **game)
{
	int			line;
	int			columns;

	line = 0;
	while (line < (*game)->map_h)
	{
		columns = 0;
		while (columns < (*game)->map_l)
		{
			if ((*game)->file_data[line][columns] == 'C')
				(*game)->nb_cake += 1;
			columns++;
		}
		line++;
	}
	if ((*game)->nb_cake == 0)
		put_error_message(7);
}

void	get_player_pos(t_data **game)
{
	int			line;
	int			columns;
	int			check;

	line = 0;
	check = 0;
	while (line < (*game)->map_h)
	{
		columns = 0;
		while (columns < (*game)->map_l)
		{
			if ((*game)->file_data[line][columns] == 'P' && check == 0)
			{
				(*game)->x_pos_player = columns;
				(*game)->y_pos_player = line;
				check = 1;
			}
			else if ((*game)->file_data[line][columns] == 'P' && check == 1)
				put_error_message(6);
			columns++;
		}
		line++;
	}
	if ((*game)->x_pos_player == 0)
		put_error_message(6);
}

void	game_proceed(t_data **game)
{
	init_window(game);
	count_present(game);
	get_player_pos(game);
	set_picture(game);
	set_max(game);
	set_enemy_pos(game); // bonus
	draw_map(game);
	setup_action(game);
	mlx_loop((*game)->mlx_ptr);
}
