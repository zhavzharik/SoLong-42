/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 16:41:21 by abridger          #+#    #+#             */
/*   Updated: 2021/10/25 17:18:31 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_move_cat(t_data **game, int i, int j)
{
	if ((*game)->step % 10 > 2 && (*game)->step % 10 < 6
		&& i / PIC_SIDE == (*game)->map_l / 2 && j == 0 && (*game)->step != 0)
	{
		if ((*game)->counter == 0)
			mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr,
				(*game)->m_1, i, j);
		else if ((*game)->counter == 1)
			mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr,
				(*game)->m_2, i, j);
		else if ((*game)->counter == 2)
			mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr,
				(*game)->m_3, i, j);
		(*game)->counter++;
		if ((*game)->counter == 3)
			(*game)->counter = 0;
	}
}

void	put_move_pump(t_data **game, int i, int j)
{
	if ((*game)->step % 10 > 5 && (*game)->step % 10 < 10
		&& i / PIC_SIDE == (*game)->map_l % 2 == 0
		&& j / PIC_SIDE == (*game)->map_h - 1 && (*game)->step != 0)
	{
		if ((*game)->counter == 0)
			mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr,
				(*game)->pump_1, i, j);
		else if ((*game)->counter == 1)
			mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr,
				(*game)->pump_2, i, j);
		else if ((*game)->counter == 2)
			mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr,
				(*game)->wall, i, j);
		else if ((*game)->counter == 3)
			mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr,
				(*game)->pump_4, i, j);
		(*game)->counter++;
		if ((*game)->counter == 4)
			(*game)->counter = 0;
	}
}

void	set_enemy_pos(t_data **game)
{
	int	i;
	int	j;

	i = (*game)->map_l / 3;
	j = (*game)->map_h / 3;
	if ((*game)->file_data[j][i] != '0')
	{
		i = 0;
		j = 0;
		while ((*game)->file_data[j][i] != '0' && j < (*game)->map_h
			&& i < (*game)->map_l)
		{
			j = 0;
			while ((*game)->file_data[j][i] != '0' && j < (*game)->map_h
				&& i < (*game)->map_l)
				j++;
			i++;
		}
	}
	if ((*game)->file_data[j][i] == '0')
	{
		(*game)->x_pos_enemy = i;
		(*game)->y_pos_enemy = j;
	}
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
		return (1);
	return (0);
}
