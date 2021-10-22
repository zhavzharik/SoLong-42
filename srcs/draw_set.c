/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:31:59 by abridger          #+#    #+#             */
/*   Updated: 2021/10/22 21:50:09 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
	(*game)->wall_rand = mlx_xpm_file_to_image((*game)->mlx_ptr, WALL_R,
			&img_width, &img_height);
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
