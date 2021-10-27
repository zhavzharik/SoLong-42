/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_put_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:45:33 by abridger          #+#    #+#             */
/*   Updated: 2021/10/27 16:09:19 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	put_empty(t_data **game, int i, int j)
{
	if (i / PIC_SIDE == (*game)->x_pos_enemy
		&& j / PIC_SIDE == (*game)->y_pos_enemy)
		put_enemy(game, i, j);
	else
		mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr,
			(*game)->space, i, j);
}

void	put_wall(t_data **game, int i, int j)
{
	if ((*game)->step % 10 > 2 && (*game)->step % 10 < 6 && !(*game)->end
		&& i / PIC_SIDE == (*game)->map_l / 2 && j == 0 && (*game)->step != 0)
	{
		put_move_cat(game, i, j);
	}
	else if ((*game)->step % 10 > 5 && (*game)->step % 10 < 10
		&& i / PIC_SIDE == (*game)->map_l % 2 == 0 && !(*game)->end
		&& j / PIC_SIDE == (*game)->map_h - 1 && (*game)->step != 0)
	{
		put_move_pump(game, i, j);
	}
	else
		mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr,
			(*game)->wall, i, j);
}

void	put_cake(t_data **game, int i, int j)
{
	mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr,
		(*game)->cake, i, j);
}

void	put_player(t_data **game, int i, int j)
{
	if ((*game)->end == 1)
		mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr,
			(*game)->enemy_3, i, j);
	else if ((*game)->flag_player == 0 && (*game)->end == 0)
		mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr,
			(*game)->player_l, i, j);
	else
		mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr,
			(*game)->player_r, i, j);
}

void	put_exit(t_data **game, int i, int j)
{
	if ((*game)->nb_cake > 0)
		mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr,
			(*game)->exit_c, i, j);
	else
		mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr,
			(*game)->exit_o, i, j);
}
