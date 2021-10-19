/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abridger <abridger@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:10:07 by abridger          #+#    #+#             */
/*   Updated: 2021/10/19 14:04:15 by abridger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	get_index(char *assets, char ch)
{
	int	indx;

	indx = 0;
	while (indx < 5)
	{
		if (assets[indx] == ch)
		{
			return (indx);
		}
		indx++;
	}
	return (indx);
}

void	draw_map(t_visual **window, t_data **game)
{
	char		*assets;
	t_action	*func;
	int			line;
	int			columns;
	int			indx;

	line = 0;
	set_picture(window, game);
	assets = create_str_assets();
	func = create_array_function();
	while (line < (*game)->map_h * PIC_SIDE)
	{
		columns = 0;
		while (columns < (*game)->map_l * PIC_SIDE)
		{
			indx = get_index(assets,
					(*game)->file_data[line / PIC_SIDE][columns / PIC_SIDE]);
			(func)[indx](window, game, columns, line);
			columns += PIC_SIDE;
		}
		line += PIC_SIDE;
	}
	mlx_loop((*window)->mlx_ptr);
	// ft_ptr_clear(assets, func);
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
