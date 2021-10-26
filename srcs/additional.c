/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 20:18:51 by abridger          #+#    #+#             */
/*   Updated: 2021/10/26 23:06:09 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_map_data(t_data **game)
{
	int	line;

	line = 0;
	// printf("Map_height: %d\n", (*game)->map_h);
	// printf("Map_length: %d\n", (*game)->map_l);
	// printf("X_POS: %d\n", (*game)->x_pos_player);
	// printf("Y_POS: %d\n", (*game)->y_pos_player);
	// printf("Number of present %d\n", (*game)->nb_cake);
	if ((*game)->file_data)
	{
		while (line < (*game)->map_h)
		{
			printf("Print_map_data\n");
			printf("%d\t line : %s\n", line, (*game)->file_data[line]);
			line++;
		}
	}
}
