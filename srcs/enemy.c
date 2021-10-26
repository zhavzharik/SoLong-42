/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 18:21:00 by abridger          #+#    #+#             */
/*   Updated: 2021/10/26 18:27:48 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	set_enemy_pos_case(t_data **game)
{
	int	i;
	int	j;

	j = 1;
	i = 1;
	while ((*game)->enem_c != 2 && j < (*game)->map_h - 1)
	{
		i = 1;
		while ((*game)->enem_c != 2 && i < (*game)->map_l - 1)
		{
			if ((*game)->file_data[j][i] == '0')
			{
				(*game)->x_pos_enemy = i;
				(*game)->y_pos_enemy = j;
				(*game)->enem_c = 2;
			}
			i++;
		}
		j++;
	}
}

void	set_enemy_pos(t_data **game)
{
	int	i;
	int	j;

	i = (*game)->map_l / 2;
	j = (*game)->map_h / 2;
	if (get_component(game, i, j) != 'P' && get_component(game, i, j) != 'C')
	{
		(*game)->x_pos_enemy = i;
		(*game)->y_pos_enemy = j;
		(*game)->enem_c = 2;
	}
	else
		set_enemy_pos_case(game);
	(*game)->enem_c = 0;
}

void	put_enemy(t_data **game, int i, int j)
{
	if (i / PIC_SIDE == (*game)->x_pos_enemy
		&& j / PIC_SIDE == (*game)->y_pos_enemy)
	{
		if ((*game)->enem_c == 0 && (*game)->end == 0)
			mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr,
				(*game)->enemy_1, i, j);
		else if ((*game)->enem_c == 1 && (*game)->end == 0)
			mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr,
				(*game)->enemy_2, i, j);
		(*game)->enem_c++;
		if ((*game)->enem_c == 2)
			(*game)->enem_c = 0;
	}
}

int	whether_enemy(t_data **game, int x, int y)
{
	if (x == (*game)->x_pos_enemy && y == (*game)->y_pos_enemy)
	{
		return (1);
	}
	return (0);
}
