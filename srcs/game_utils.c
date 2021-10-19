/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 15:17:08 by abridger          #+#    #+#             */
/*   Updated: 2021/10/19 15:43:09 by abridger         ###   ########.fr       */
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
	printf("Number of present %d\n", (*game)->nb_cake);
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
	printf("X_pos: %d\n", (*game)->x_pos_player);
	printf("Y_pos: %d\n", (*game)->y_pos_player);
}
