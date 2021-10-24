/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_put.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:45:33 by abridger          #+#    #+#             */
/*   Updated: 2021/10/24 20:04:46 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_empty(t_data **game, int i, int j)
{
	mlx_put_image_to_window((*game)->mlx_ptr, (*game)->win_ptr,
		(*game)->space, i, j);
}

void	put_wall(t_data **game, int i, int j)
{
	if ((*game)->step % 10 > 2 && (*game)->step % 10 < 6
		&& i / PIC_SIDE == (*game)->map_l / 2 && j == 0 && (*game)->step != 0)
	{
		put_move_cat(game, i, j);
	}
	else if ((*game)->step % 10 > 5 && (*game)->step % 10 < 10
		&& i / PIC_SIDE == (*game)->map_l % 2 == 0
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
	if ((*game)->flag_player == 0)
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
