/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_put.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:45:33 by abridger          #+#    #+#             */
/*   Updated: 2021/10/18 16:51:29 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_empty(t_visual **window, t_data **game, int i, int j)
{
	mlx_put_image_to_window((*window)->mlx_ptr, (*window)->win_ptr,
		(*game)->space, i, j);
}

void	put_wall(t_visual **window, t_data **game, int i, int j)
{
	mlx_put_image_to_window((*window)->mlx_ptr, (*window)->win_ptr,
		(*game)->wall, i, j);
}

void	put_cake(t_visual **window, t_data **game, int i, int j)
{
	mlx_put_image_to_window((*window)->mlx_ptr, (*window)->win_ptr,
		(*game)->cake, i, j);
}

void	put_player(t_visual **window, t_data **game, int i, int j)
{
	mlx_put_image_to_window((*window)->mlx_ptr, (*window)->win_ptr,
		(*game)->player, i, j);
}

void	put_exit(t_visual **window, t_data **game, int i, int j)
{
	mlx_put_image_to_window((*window)->mlx_ptr, (*window)->win_ptr,
		(*game)->exit, i, j);
}
