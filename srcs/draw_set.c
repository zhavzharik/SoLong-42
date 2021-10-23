/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:31:59 by abridger          #+#    #+#             */
/*   Updated: 2021/10/23 16:41:21 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	set_move_pic(t_data **game)
{
	int		img_width;
	int		img_height;

	(*game)->m_1 = mlx_xpm_file_to_image((*game)->mlx_ptr, MOVE_1,
			&img_width, &img_height);
	(*game)->m_2 = mlx_xpm_file_to_image((*game)->mlx_ptr, MOVE_2,
			&img_width, &img_height);
	(*game)->m_3 = mlx_xpm_file_to_image((*game)->mlx_ptr, MOVE_3,
			&img_width, &img_height);
	(*game)->m_4 = mlx_xpm_file_to_image((*game)->mlx_ptr, MOVE_4,
			&img_width, &img_height);
	(*game)->m_5 = mlx_xpm_file_to_image((*game)->mlx_ptr, MOVE_5,
			&img_width, &img_height);
}

void	set_picture(t_data **game)
{
	int		img_width;
	int		img_height;

	(*game)->wall = mlx_xpm_file_to_image((*game)->mlx_ptr, WALL,
			&img_width, &img_height);
	(*game)->player_l = mlx_xpm_file_to_image((*game)->mlx_ptr, GHOST_L,
			&img_width, &img_height);
	(*game)->player_r = mlx_xpm_file_to_image((*game)->mlx_ptr, GHOST_R,
			&img_width, &img_height);
	(*game)->cake = mlx_xpm_file_to_image((*game)->mlx_ptr, CAKE,
			&img_width, &img_height);
	(*game)->space = mlx_xpm_file_to_image((*game)->mlx_ptr, GROUND,
			&img_width, &img_height);
	(*game)->exit_c = mlx_xpm_file_to_image((*game)->mlx_ptr, PORT_C,
			&img_width, &img_height);
	(*game)->exit_o = mlx_xpm_file_to_image((*game)->mlx_ptr, PORT_O,
			&img_width, &img_height);
	set_move_pic(game);
}

void	execute_func(t_data **game, int indx, int i, int j)
{
	if (indx == 0)
		put_empty(game, i, j);
	else if (indx == 1)
		put_wall(game, i, j);
	else if (indx == 2)
		put_cake(game, i, j);
	else if (indx == 3)
		put_player(game, i, j);
	else if (indx == 4)
		put_exit(game, i, j);
}
