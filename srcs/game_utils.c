/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:17:08 by abridger          #+#    #+#             */
/*   Updated: 2021/10/20 22:27:39 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
	// printf("Number of present %d\n", (*game)->nb_cake); // delete
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
				ft_puterror();
			columns++;
		}
		line++;
	}
	// printf("X_pos: %d\n", (*game)->x_pos_player); // delete
	// printf("Y_pos: %d\n", (*game)->y_pos_player); // delete
}

void	game_proceed(t_visual **window, t_data **game)
{
	t_action	*func;

	init_window(*window, *game);
	count_present(game);
	get_player_pos(game);
	set_picture(window, game);
	func = create_array_function();
	draw_map(window, game, func);
	// setup_action(game, window);
	hook_test(window);
	// mlx_loop((*window)->mlx_ptr);
	// ft_ptr_clear(assets, func);
}
