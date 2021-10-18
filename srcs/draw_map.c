/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:10:07 by abridger          #+#    #+#             */
/*   Updated: 2021/10/18 17:22:59 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_map(t_visual **window, t_data **game)
{
	char		**assets;
	t_action	*func;
	int			ind_f;
	int			i;
	int			j;

	i = 0;
	ind_f = 0;
	set_picture(window, game);
	assets = create_array_assets();
	func = create_array_function();
	while (i < (*game)->map_l)
	{
		j = 0;
		while (j < (*game)->map_h)
		{
			while (assets[ind_f] && ft_strcmp(assets[ind_f],
					&(*game)->file_data[i][j]))
				ind_f++;
			if (ind_f > 4)
				ft_puterror();
			else
				(func)[ind_f](window, game, i * PIC_SIDE, j * PIC_SIDE);
			j++;
		}
		i++;
	}
	mlx_loop((*window)->mlx_ptr);
}

void	draw_test1(t_visual **window, t_data **game)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	set_picture(window, game);
	while (i < (*game)->map_l * PIC_SIDE)
	{
		j = 0;
		while (j < (*game)->map_h * PIC_SIDE)
		{
			mlx_put_image_to_window((*window)->mlx_ptr, (*window)->win_ptr,
				(*game)->wall, i, j);
			j += PIC_SIDE;
		}
		i += PIC_SIDE;
	}
	mlx_loop((*window)->mlx_ptr);
}

void	draw_test2(t_visual **window, t_data **game)
{
	int		i;
	int		j;

	i = 0;
	set_picture(window, game);
	while (i < (*game)->map_l * PIC_SIDE)
	{
		mlx_put_image_to_window((*window)->mlx_ptr, (*window)->win_ptr,
			(*game)->wall, i, 0);
		i += PIC_SIDE;
	}
	j = PIC_SIDE;
	i = 0;
	while (j < (*game)->map_h * PIC_SIDE)
	{
		mlx_put_image_to_window((*window)->mlx_ptr, (*window)->win_ptr,
			(*game)->space, i, j);
		j += PIC_SIDE;
	}
	j = PIC_SIDE;
	i = PIC_SIDE;
	while (j < (*game)->map_h * PIC_SIDE)
	{
		mlx_put_image_to_window((*window)->mlx_ptr, (*window)->win_ptr,
			(*game)->cake, i, j);
		j += PIC_SIDE;
	}
	j = PIC_SIDE;
	i = PIC_SIDE * 2;
	while (j < (*game)->map_h * PIC_SIDE)
	{
		mlx_put_image_to_window((*window)->mlx_ptr, (*window)->win_ptr,
			(*game)->player, i, j);
		j += PIC_SIDE;
	}
	j = PIC_SIDE;
	i = PIC_SIDE * 3;
	while (j < (*game)->map_h * PIC_SIDE)
	{
		mlx_put_image_to_window((*window)->mlx_ptr, (*window)->win_ptr,
			(*game)->exit, i, j);
		j += PIC_SIDE;
	}
	mlx_loop((*window)->mlx_ptr);
}
